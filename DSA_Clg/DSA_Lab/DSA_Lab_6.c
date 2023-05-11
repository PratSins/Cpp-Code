#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

char stack[200];
int top = -1;
void push(char e)
{    stack[++top] = e;    }
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void clearStack()
{
    top = -1;
}
int isStackEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}


int isPalin(char str[])
{
    int l = strlen(str);
    int i, mid = l / 2;
 
    for (i = 0; i < mid; i++){
        push(str[i]);
    }

    if (l % 2 != 0)
        i++;
    

    while (str[i] != '\0') 
    {
        char e = pop();
        if (e != str[i])
            return 0;

        i++;
    }
    return 1;
}


int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}


int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
int isOpenBrac(char c)
{
    if (c=='(' || c=='{' || c=='[')
        return 1;
    else
        return 0;
}
int isClosedBrac(char c)
{
    if (c==')' || c=='}' || c==']')
        return 1;
    return 0;
}


int main()
{
    printf("\nPROGRAM 1\n");
    char str[200];
    printf("Enter a string:\n  -> ");
    gets(str);

    if (isPalin(str)) {
        printf("\nThe entered String is Pallindrome\n");
    }
    else {
        printf("\nThe entered String is NOT Pallindrome\n");
    }
    printf("\n");

    printf("\nPROGRAM 2\n");
    clearStack();
    char expr[100];
    char *eptr, x;
    printf("Enter the expression :\n  -> ");
    scanf("\n%s",expr);
    printf("\n");
    eptr = expr;
    
    while(*eptr != '\0')
    {
        if(isalnum(*eptr))
            printf("%c ",*eptr);
        else if(*eptr == '(')
            push(*eptr);
        else if(*eptr == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*eptr))
                printf("%c ",pop());
            push(*eptr);
        }
        eptr++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
    printf("\n");

    printf("\nPROGRAM 3\n");
    printf("Enter a string:\n  -> ");
    
    fflush(stdin);
    gets(str);

    clearStack();
    int i=0, flag=1;

    while(str[i]!='\0')
    {
        char c = str[i];
        if(isOpenBrac(c))
        {
            push(c);
        }
        else if(isClosedBrac(c))
        {
            if (isStackEmpty())
            {
                flag = 0;
                break;
            }
            else
            if (!isMatchingPair(pop(), c)){

                flag = 0;
                break;
            }
        }

        i++;
    }
    if(!isStackEmpty())
    {
        flag=0;
    }
    if (flag) {
        printf("\nBalanced Expression\n");
    }
    else {
        printf("\nUnbalanced Expression\n");
    }
    printf("\n");
    return 0;
}