#include<stdio.h>
#include<stdlib.h>

int numOfDigits(int number)
{
    int number_of_digits;
    int c = 1;
    float start = 10;
    while (((float)number/start)>=1){
        c = c + 1;
        start*=10;
    }
    return c;
}

int sumOfDigits(int num)
{
    int changer = num;
    int start = 0;
    int base = 10;
    int answer = 0;
    int num_of_digits = numOfDigits(num);
    while (start < num_of_digits){
        int digit = changer%base;
        changer = (changer - digit)/10;
        answer = answer + digit;
        start = start + 1;
    }
    return answer;
}

int hashFunc_1(int key, int offset, int size)
{
    return (sumOfDigits(key) + (offset * offset))%size; 
}

int collision_count_insert(int * hash, int len, int key){
    int count = 0;
    int offset = 0;
    int index = hashFunc_1(key, offset, len);
    while (hash[index] != 0 && offset < len){
        offset++;
        count++;
        index = hashFunc_1(key, offset, len);
    }

    if (hash[index] == 0){
        hash[index] = key;
    }

    return count;
}

struct node_2{
    int key;
    int value;
};

int hashFunc_2(int key,int offset)
{
    return (key+offset)%10;
}

void insert_hash_2(int key,int hash_table[10][2])
{
    int offset = 0;
    int hash_index = hashFunc_2(key,offset);
    while (hash_table[hash_index][0]!=0 && offset<10){
        offset++;
        hash_index = hashFunc_2(key,offset);
    }
    if (hash_table[hash_index][0]==key){hash_table[hash_index][1]++;}
    else if (hash_table[hash_index][0]==0){hash_table[hash_index][0]=key;hash_table[hash_index][1]++;}
}

struct node
{
    int data;
    struct node * next;
};

typedef struct node node;

int hashFunc_3(int k, int offset, int hl)
{
    return (k + offset)%hl;
}

void insert_hash_3(int * hash, int len, int key)
{
    int offset = 0;
    int index = hashFunc_3(key, offset, len);
    while (hash[index] != 0 && offset < len){
        offset++;
        index = hashFunc_3(key, offset, len);
    }

    if (hash[index] == 0){
        hash[index] = key;
    }else{
        printf("hash full");
    }
}

int search(int * hash, int len, int key)
{
    int offset = 0;
    int index = hashFunc_3(key, offset, len);
    while (hash[index] != 0 && offset < len){
        if (hash[index] == key){
            return 1;
        }
        offset++;
        index = hashFunc_3(key, offset, len);
    }

    return 0;
}
void printhash(int * hash, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", hash[i]);
    } 
    printf("\n");
}

void getpairs(int * hash, int len, int sum)
{
    for (int i = 0; i < len; i++){
        if (hash[i] != 0)
        {
            if (search(hash, len, sum - hash[i]))
            {
                printf("(%d, %d), ", hash[i], sum - hash[i]);
            }
        }
    }
    printf("\n");
}
void q1()
{
    printf("\n----------QUESTION-1----------\n");
    int hash_size,l,S;
    printf("Enter the length of hash table: ");
    scanf("%d",&hash_size);

    printf("\nEnter the length of the array: ");
    scanf("%d",&l);

    int * hash_table = (int*)malloc(sizeof(int)*hash_size);
    for (int i = 0; i < hash_size; i++){hash_table[i] = 0;}
    int arr[l],count=0;
    for (int i=0;i<l;i++)
    {
        printf("Enter the %d th element: ",i+1);
        scanf("%d",&arr[i]);
        count = count + collision_count_insert(hash_table,hash_size,arr[i]);
    }
    printf("Number of collisions are: %d\n",count);
}
void q2()
{
    printf("\n----------QUESTION-2----------\n");
    int l1,l2;
    printf("Enter the length of both arrays with space in between: ");
    scanf("%d %d",&l1,&l2);

    int h1[10][2] = {0};
    int h2[10][2] = {0};
    int a1[l1],a2[l2];

    for (int i=0;i<l1;i++)
    {
        printf("\nEnter the %d th element for first array: ",i+1);
        scanf("%d",&a1[i]);
        insert_hash_2(a1[i],h1);
    }

    for (int i=0;i<l2;i++)
    {
        printf("\nEnter the %d th element for second array: ",i+1);
        scanf("%d",&a2[i]);
        insert_hash_2(a2[i],h2);
    }

    int check = 1;
    for (int i=0;i<10;i++)
    {
        if (h1[i][0]!=h2[i][0] && h1[i][1]!=h2[i][1])
        {   int check=0;break; }
    }
    if (check==1)
    {   printf("True");}
    else
    {   printf("False");} 
//*******************************************
    //Program Complexity is O(N)
//*******************************************
}
void q3()
{
    printf("\n----------QUESTION-3----------\n");
    int hash_size,l,S;
    printf("Enter the length of hash table: ");
    scanf("%d",&hash_size);

    printf("\nEnter the length of the array: ");
    scanf("%d",&l);

    int * hash_table = (int*)malloc(sizeof(int)*hash_size);
    for (int i = 0; i < hash_size; i++)
    {   hash_table[i] = 0;  }
    int arr[l];
    for (int i=0;i<l;i++)
    {
        printf("Enter the %d th element: ",i+1);
        scanf("%d",&arr[i]);
        insert_hash_3(hash_table,hash_size,arr[i]);
    }

    printf("\nEnter the value of S: ");
    scanf("%d",&S);
    getpairs(hash_table,hash_size,S);
}
int main()
{
    q1();
    q2();
    q3();
    return 0;
}