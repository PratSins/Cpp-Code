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