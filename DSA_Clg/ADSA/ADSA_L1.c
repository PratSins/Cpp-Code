//PROGRAM 1
#include <stdio.h>
#include <stdlib.h>

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
    printf("Enter a string:\n  -> ");
    char str[200];
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


//----------------------------------------------------------------
// PROGRAM 2

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct Node * next;
} Node;
Node *temp = NULL, *a1 = NULL, *a2 = NULL;

Node* Create(int A[], int n)
{
	int i;
	Node *t, *last;
	temp = (Node *) malloc(sizeof(Node));
	temp->data = A[0];
	temp->next = NULL;
	last = temp;

	for (i = 1; i < n; i++)
	{
		t = (Node *) malloc(sizeof(Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
	return temp;
}

void Display(Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void concatenate(Node *a1, Node *a2)
{
	Node *p = a1;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = a2;
	a2 = NULL;
}

int main()
{
	int A[] = { 1, 2, 3, 4 };
	int B[] = { 5, 6, 7, 8 };
	a1 = Create(A, 4);
	a2 = Create(B, 4);

	printf("\nList 1 :  ");
	Display(a1);

	printf("\nList 2 :  ");
	Display(a2);

	concatenate(a1, a2);
	printf("\n\nConcatenated list: \n");
	Display(a1);
	return 0;
}