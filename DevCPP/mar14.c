#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPrime(int n) 
{
    if(n == 2) {
        return true;
    } else {
        for(int i = 2; i < n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
    }
    return true;
}
bool isEven(int n)
{
    if(n % 2 == 0) {
        return true;
    } else {
        return false;
    }
} 

void prog1() {
    FILE *fp, *file; 
    char ch; 
    int word=1,character=1;
    char filename[70]; 
    file = fopen("test.txt","w");
    if(file==NULL) 
    { 
        printf("File does not exist or can not be opened."); 
        exit(EXIT_FAILURE);
    } else {
        char *str = "test line 1\ntest line 2\ntest line 3\ntest line 4";
        fputs(str,file);
    }
    fclose(file);
	printf("Input the filename to be opened : ");
	scanf("%s",filename);    
    
    fp=fopen(filename,"r"); 
    if(fp==NULL) 
    { 
        printf("File does not exist or can not be opened."); 
    } 
    else 
        { 
          ch=fgetc(fp); 
          printf("The content of the file %s are : \n",filename); 
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                if(ch == ' ' || ch == '\n')
                    { 
                        word++; 
                    }
                    else
                    {
                        character++; 
                    }
                ch=fgetc(fp); 
            }
        printf("\nThe number of words in the  file %s are : %d\n",filename,word); 
        printf("The number of characters in the  file %s are : %d\n\n",filename,character-1);         
        } 
    fclose(fp); 
}
void prog2()
{
    FILE *fp,*fpeven,*fpodd,*fpprime; 
    int n;
    char filename[30]; 
    int arr[10] = {22, 45, 48, 65, 11, 34, 88, 99, 69, 13};
    fp = fopen("numbers.txt","w");
    if(fp == NULL)
    {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        for(int i = 0; i < 10; i++) {
            fprintf(fp, "%d ", arr[i]);
        }
    }
    fclose(fp);
	printf("Input the filename to be opened : ");
	scanf("%s",filename);    

    fp=fopen(filename,"r"); 
    fpeven=fopen("Even_numbers.txt","w");
    fpodd=fopen("Odd_numbers.txt","w");
    fpprime=fopen("Prime_numbers.txt","w");
    if(fp == NULL || fpeven == NULL || fpodd == NULL || fpprime == NULL)
    {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        while (fscanf(fp, "%d", &n) != -1)
        {
            if (isPrime(n))
                fprintf(fpprime, "%d ", n);
            else if (isEven(n))
                fprintf(fpeven, "%d ", n);
            else
                fprintf(fpodd, "%d ", n);

        }
    }
    fclose(fp);
    fclose(fpeven);
    fclose(fpodd);
    fclose(fpprime);
    fp=fopen("numbers.txt","r"); 
    fpeven=fopen("Even_numbers.txt","r");
    fpodd=fopen("Odd_numbers.txt","r");
    fpprime=fopen("Prime_numbers.txt","r");
    if(fp == NULL || fpeven == NULL || fpodd == NULL || fpprime == NULL)
    {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        char c;
        printf("The numbers.txt file contains:\n");
        while ((c = fgetc(fp)) != EOF)
        {
            printf("%c", c);
        }
        printf("\n");
        printf("The Prime_numbers.txt file contains:\n");
        while ((c = fgetc(fpprime)) != EOF)
        {
            printf("%c", c);
        }
        printf("\n");
        printf("The Even_numbers file contains:\n");
        while ((c = fgetc(fpeven)) != EOF)
        {
            printf("%c", c);
        }
        printf("\n");
        printf("The Odd_numbers.txt file contains:\n");
        while ((c = fgetc(fpodd)) != EOF)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    fclose(fp);
    fclose(fpeven);
    fclose(fpodd);
    fclose(fpprime);
}
void prog3()
{
    FILE *file1,*file2,*file3;
    file1 = fopen("File1.txt","w");
    file2 = fopen("File2.txt","w");
    if(file1 == NULL || file2 == NULL)
    {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        int f = 0;
        printf("Write contents of file 1: ");
        while(f == 0) {
            char c;
            scanf("%c",&c);
            if(c == '\n') {
                break;
            } else {
                fputc(c,file1);
            }
        }
    
        printf("Write contents of file 2: ");
        while(f == 0) {
            char c;
            scanf("%c",&c);
            if(c == '\n') {
                break;
            } else {
                fputc(c,file2);
            }
        }
    }
    fclose(file1);
    fclose(file2);
    file1 = fopen("File1.txt","r");
    file2 = fopen("File2.txt","r");
    file3 = fopen("File.txt","w");
    if(file1 == NULL || file2 == NULL || file3 == NULL)
    {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Merged_File.txt: ");
        char c;
        while((c = fgetc(file1)) != EOF) {
            fputc(c, file3);
            printf("%c", c);
        }
        
        while((c = fgetc(file2)) != EOF) {
            fputc(c, file3);
            printf("%c", c);
        }
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
}
void prog4()
{
    FILE *fp,*fp1;
    fp = fopen("File4.txt","w");

    if(fp == NULL) {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        int f = 0;
        printf("Write contents of file: ");
        while(f == 0) {
            char c;
            scanf("%c",&c);
            if(c == '\n') {
                break;
            } else {
                fputc(c,fp);
            }
        }
    }
    fclose(fp);
    fp = fopen("File4.txt","r");
    fp1 = fopen("Temp_File.txt","w");
    if(fp == NULL || fp1 == NULL) {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        char d;
        while((d = fgetc(fp)) != EOF) {
            if(isalpha(d) && isupper(d)) {
                fputc(tolower(d), fp1);
            } else if(isalpha(d), islower(d)) {
                fputc(toupper(d), fp1);
            } else {
                fputc(d, fp1);
            }
        }
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("File4.txt","w");
    fp1 = fopen("Temp_File.txt","r");
    if(fp == NULL || fp1 == NULL) {
        printf("Unable to open file Or file does not exist\n");
        exit(EXIT_FAILURE);
    } else {
        printf("After converting the lowecase letters to uppercase and vice-versa the contents of file is: \n");

        char e;
        while((e = fgetc(fp1)) != EOF) {
            fputc(e,fp);
            printf("%c", e);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("Temp_file.txt");
}
int main()
{
    printf("PROGRAM 1\n");
    prog1();
    printf("\n");

    printf("PROGRAM 2\n");
    prog2();
    printf("\n");

    printf("PROGRAM 3\n");
    prog3();
    printf("\n");

    printf("PROGRAM 4\n");
    prog4();
    printf("\n");
    return 0;
}