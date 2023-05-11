#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct complex{
    float real;
    float imag;
}comp;

comp add(comp x,comp y){
    comp r;
    r.real=x.real+y.real;
    r.imag=x.imag+y.imag;
    return r;
}
comp sub(comp x,comp y){
    comp r;
    r.real=x.real-y.real;
    r.imag=x.imag-y.imag;
    return r;
}
comp mul(comp x,comp y){
    comp r;
    r.real=(x.real*y.real)-(x.imag*y.imag);
    r.imag=(x.imag*y.real)+(x.real*y.imag);
    return r;
}
comp div(comp x,comp y){
    comp r;
    float d=pow(y.real,2)+pow(y.imag,2);
    r.real=((x.real*y.real)+(x.imag*y.imag))/d;
    r.imag=((x.imag*y.real)-(x.real*y.imag))/d;
    return r;
}
char *strcat(char *dest,const char *src){
    char *end=dest;
    while(*end!='\0'){
        end++;
    }
    int i;
    for(i=0;*src!='\0';i++){
        *(end+i)=*(src+i);
    }
    *(end+i)='\0';
    return dest;
}
typedef struct Stud_Data
{
    char First_Name[40];
    char Last_Name[40];
    int Roll_no;
    float CGPA;
    int Courses[10];
    int N;
}data;
data Students[50];
int count3=0;
int cgpa[50];
int rollno[50];
int is_in(int x){
    int i;
    for(i=0;i<count3;i++){
        if(x==rollno[i]){
            return 1;
        }
    }
    rollno[i]=x;
    return 0;
}
void addStudent(){
    int n;
    printf("Enter Roll No=");
    scanf("%d",&n);
    if(!is_in(n)){
        Students[count3].Roll_no=n;
        
    }
    else{
        printf("Roll No already present!!! Try again\n");
        return;
    }
    printf("Enter First Name=");
    scanf("%s",Students[count3].First_Name);
    printf("Enter Last Name=");
    scanf("%s",Students[count3].Last_Name);
    printf("Enter CGPA=");
    scanf("%f",&Students[count3].CGPA);
    cgpa[count3]=Students[count3].CGPA;
    printf("Enter size of Courses array=");
    scanf("%d",&Students[count3].N);
    for(int i=0;i<Students[count3].N;i++){
        printf("Enter Course No.%d=",i+1);
        scanf("%d",&Students[count3].Courses[i]);
    }
    count3++;
}
void findStu(int x){
    for(int i=0;i<count3;i++){
        if(x==Students[i].Roll_no){
            printf("\nName=%s %s",Students[i].First_Name,Students[i].Last_Name);
            printf("\nCGPA=%f",Students[i].CGPA);
            printf("\nCourses ID=>");
            for(int j=0;i<Students[j].N;j++){
                printf("%d ",Students[i].Courses[j]);
            }
            return;
        }
    }
    printf("\nRecord Not Found");
}
void findStudent(char *A){
    int count=0;
    for(int i=0;i<count3;i++){
        if(!strcmp(A,Students[i].First_Name)){
            count++;
            printf("\nRoll_no=%d",Students[i].Roll_no);
            printf("\nCGPA=%f",Students[i].CGPA);
            printf("\nCourses ID=>");
            for(int j=0;i<Students[j].N;j++){
                printf("%d ",Students[i].Courses[j]);
            }
            printf("\n");
        }
    }
    if(count==0)
    {printf("\nRecord Not Found");}
}
void findS(int x){
    int count=0;
    for(int i=0;i<count3;i++){
        for(int k=0;k<Students[i].N;k++){
            if(x==Students[i].Courses[k]){
                count++;
                printf("\nRoll_no=%d",Students[i].Roll_no);
                printf("\nName=%s %s",Students[i].First_Name,Students[i].Last_Name);
                printf("\nCGPA=%f",Students[i].CGPA);
                printf("\nCourses ID=>");
                for(int j=0;j<Students[i].N;j++){
                    printf("%d ",Students[i].Courses[j]);
                }
                printf("\n");
            }
        }
    }
    if(count==0){
        printf("\nRecord Not Found");
    }
}
void delStud(int x){
    int index;
    for(index=0;index<count3;index++){
        if(x==Students[index].Roll_no)
        break;
    }
    for(int j=index;j<(count3-1);j++){
        Students[j]=Students[j+1];
        rollno[j]=rollno[j+1];
        cgpa[j]=cgpa[j+1];
    }
    count3--;
}
void update(int x){
    int p,index;
    printf("\n1.Update First Name");
    printf("\n1.Update Last Name");
    printf("\n1.Update Roll-No");
    printf("\n1.Update CGPA");
    printf("\n1.Update Course ID");
    printf("\nEnter Option Number==>");
    scanf("%d",&p);
    for(index=0;index<count3;index++){
        if(p==Students[index].Roll_no)
        {break;}
    }
        switch(p){
            case 1:
            printf("Enter New First Name=");
            scanf("%s",Students[index].First_Name);
            break;
            case 2:
            printf("Enter Last Name=");
            scanf("%s",Students[index].Last_Name);
            break;
            case 3:
            int n;
            printf("Enter Roll No=");
            scanf("%d",&n);
            if(!is_in(n)){
            Students[index].Roll_no=n;
            }
            else{
            printf("Roll No already present!!! Try again\n");
            return;
            }
            break;
            case 4:
            printf("Enter CGPA=");
            scanf("%f",&Students[index].CGPA);
            cgpa[index]=Students[index].CGPA;
            break;
            case 5:
            printf("Enter size of Courses array=");
            scanf("%d",&Students[index].N);
            for(int i=0;i<Students[index].N;i++){
            printf("Enter Course No.%d=",i+1);
            scanf("%d",&Students[index].Courses[i]);
            }
            break;
    }
}
void main(){
    printf("\n\n Program-1\n\n");
    comp n1,n2,res;
    char o;
    scanf("%f %f\n",&n1.real,&n1.imag);
    scanf("%c\n",&o);
    scanf("%f %f",&n2.real,&n2.imag);
    switch (o)
    {
    case '+':
    res=add(n1,n2);
    printf("%f %f",res.real,res.imag);
    break;
    case '-':
    res=sub(n1,n2);
    printf("%f %f",res.real,res.imag);
    break;
    case '*':
    res=mul(n1,n2);
    printf("%f %f",res.real,res.imag);
    break;
    case '/':
    res=div(n1,n2);
    printf("%f %f",res.real,res.imag);
    break;
    default:
    printf("Invalid Operator!!!!");
    break;
    }
    printf("\n\n Program-2\n\n");
    char src[100];
    char dest[100];
    scanf("%s",dest);
    scanf("%s",src);
    strcat(dest,src);
    printf("%s",dest);
    printf("\n\n Program-3\n\n");
    int m,n5;
    char str[40];
    int flag=0;
    printf("Menu--->\n");
    printf("1. Add Student \n2. Find(by roll no)\n");
    printf("3. Find(by first name) \n4. Find(by course-id)\n");        
    printf("5. Total No. of students \n6. Delete Student(by roll-no)\n");
    printf("7. Update Student  \n8.Print Student Statistics\n");
    printf("9. Print Student Statistics \n10. End\n");
    while(flag==0){
        printf("\nEnter Option Number==>");
        scanf("%d",&m);
        switch(m){
            case 1:
            addStudent();
            break;
            case 2:
            printf("Enter The Roll No=");
            scanf("%d",&n5);
            findStu(n5);
            break;
            case 3:
            printf("Enter First name=");
            scanf("%s",str);
            findStudent(str);
            break;
            case 4:
            printf("Enter Course ID=");
            scanf("%d",&n5);
            findS(n5);
            break;
            case 5:
            printf("\nTotal No. of Students=%d\n",count3);
            break;
            case 6:
            printf("Enter The Roll No=");
            scanf("%d",&n5);
            delStud(n5);
            break;
            case 7:
            printf("Enter The Roll No=");
            scanf("%d",&n5);
            update(n5);
            break;
            case 8:
            printf("\n Statistics=");
            break;
            case 9:
            printf("Course Summary");
            break;
            default:
            flag=1;
        }
    }
}