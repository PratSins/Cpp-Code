#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{
    char name[50];
    char id[20];
    float bsal;
    int aper;
    struct employee *next;
} Employee;

Employee *newEmp(char n[50], char id[20], float s, int pr)
{
    Employee *p = (Employee*)malloc(sizeof(Employee));
    strcpy(p->name,n);
    p->bsal = s;
    strcpy(p->id,id);
    p->aper = pr;
}
Employee *createEmployee(Employee *root, char n[50], char id[20], float s, int pr)
{

    Employee *p = newEmp(n,id,s,pr);
    if(root == NULL)
        root = p;
    else
    {
        Employee *ptr = root;
        while(ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=p;
    }
    return root;
}
float calculateSalary(Employee *emp){
    float sal = emp->bsal + (emp->bsal * emp->aper)/100.0;
    return sal;
}
void searchEmployeebyID(char id[], Employee *root)
{
    Employee *p = root;
    int flag = 0;

    while(p != NULL)
    {
        if(strcmp(id,p->id))
        {
            printf("Name = %s\nID = %s\nBasic salary = %f\nAllowance Percentage = %d\n",p->name,p->id,p->bsal,p->aper);
            printf("Salary = %d\n",calculateSalary(p));
            flag=1;
            break;
        }
        p = p->next;
    }
    if(flag==0)
        printf("Employee ID Invalid!!!");
}
void listEmployees(Employee *root)
{
    Employee *p = root;
    int k=0;
    printf("\nList of Employees:\n");
    while(p != NULL)
    {
        k++;
        printf("Employee %d: Name = %s\n",k,p->name);
        p = p->next;
    }
}
int main()
{
    Employee *root = NULL;
    int n, a;
    float k;
    char nm[50], d[20];
    printf("\nEnter the Number of Employees(<10): ");
    scanf("%d",&n);
    if(n>10)
        return 0;
    
    for(int i = 1; i<=n;i++)
    {
        printf("\nEnter Employee - %d details:\n",i);
        scanf("%s",&nm);  scanf("%s",&d);
        scanf("%f",&k);   scanf("%d",&a);
        root = createEmployee(root,nm,d,k,a);
    }
    listEmployees(root);
    printf("Enter ID to search:");
    scanf("%s",&d);
    searchEmployeebyID(d,root);
    return 0;
}