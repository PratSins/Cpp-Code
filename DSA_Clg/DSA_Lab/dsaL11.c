

// PROGRAM ** 1 **
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node* createBN(int data)
{
    struct node* bnode = (struct node*)malloc(sizeof(struct node));

    bnode->data = data;
    bnode->left = NULL;
    bnode->right = NULL;

    return bnode;
}

void addchildNode(struct node* root,int data)
{
    if (data==root->data)
        return;

    if (data<root->data)
    {
        if (root->left!=NULL){addchildNode(root->left,data);}
        else{root->left = createBN(data);}
    }
    else
    {
        if (root->right!=NULL)
        {
            addchildNode(root->right,data);
        }
        else
        {
            root->right=createBN(data);
        }
    }
}

int binary_i = 0;
void printInOrder(struct node* root,int a[])
{
    if (root==NULL)
        return;

    printInOrder(root->left,a);
    a[binary_i++] = root->data;
    printInOrder(root->right,a);
}

int binary_i_rev = 0;
void printRIO(struct node* root,int a[])
{
    if (root==NULL)
        return;
    
    printRIO(root->right,a);
    a[binary_i_rev++] = root->data;
    printRIO(root->left,a);
}

int main()
{
    printf("\nQUESTION-1\n");

    int l;
    printf("Enter the number of nodes in binary tree: ");
    scanf("%d",&l);

    int val,k;
    printf("\nEnter the value of k: ");
    scanf("%d",&k);

    printf("\nEnter the root node of the binary tree: ");
    scanf("%d",&val);

    struct node* root = createBN(val);

    for (int i=1;i<l;i++)
    {
        printf("\nEnter the node: ");
        scanf("%d",&val);
        addchildNode(root,val);
    }

    int bin_arr[l];
    printRIO(root , bin_arr);

    printf("\nThe Reverse InOrder Traversal is: ");

    for (int i=0;i<l;i++){
        printf("%d ",bin_arr[i]);
    }


    if (k>l){
        printf("\nThe value of k is greater than number of nodes in binary tree");
    }
    else{
        printf("\nThe kth (%d th) largest node in Binary tree is: %d",k,bin_arr[k-1]);
    }
    return 0;
}

// PROGRAM ** 2 **
#include <stdio.h>
isheap(int arr[], int i, int n)
{
	if (i >= (n - 1) / 2)
		return 1;
	if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2] && isheap(arr, 2 * i + 1, n) && isheap(arr, 2 * i + 2, n))
		return 1;

	return 0;
}
int main()
{
    printf("\n Question 2 \n");
	int arr[] = { 90, 15, 10, 7, 12, 2, 7, 3 };
	int n = sizeof(arr) / sizeof(int) - 1;

	isheap(arr, 0, n) ? printf("Yes") : printf("No");
	return 0;
}

// PROGRAM ** 3 **
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
} Node;
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
int bubbleSort(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped;
  
    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;
            if (p1->data > p2->data) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            
            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
}
  
void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("\n");
}

void insertAtTheBegin(struct Node** start_ref, int data)
{
    struct Node* ptr1
        = (struct Node*)malloc(sizeof(struct Node));
  
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

int main()
{
    printf("\nPROGRAM 3\n");
    int arr[] = {87, 25, 17, 42, 3, 50 ,0};
    int list_size, i;
    struct Node* begin = NULL;
    list_size = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < list_size; i++)
        insertAtTheBegin(&begin, arr[i]);

    printf("Linked list before sorting\n");
    printList(begin);
    bubbleSort(&begin, list_size);
    printf("Linked list after sorting\n");
    printList(begin);
    return 0;
}