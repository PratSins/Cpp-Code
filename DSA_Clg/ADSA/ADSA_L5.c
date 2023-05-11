#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode
{
	int data;
	struct Bnode* left;
	struct Bnode* right;
} Node;
enum nodeColor {
  RED,
  BLACK
};
struct rbNode {
  int data, color;
  struct rbNode *link[2];
};

int *merge(int arr1[], int arr2[], int m, int n)
{
	int *mergedArr;
    mergedArr = (int *) malloc(sizeof(int) * (m+n));

	int i = 0, j = 0, k = 0;

	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j]){
			mergedArr[k] = arr1[i];
			i++;
		}
		else{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < m){
		mergedArr[k] = arr1[i];
		i++; k++;
	}
	while (j < n){
		mergedArr[k] = arr2[j];
		j++; 
        k++;
	}
	return mergedArr;
}
Node* newNode(int data)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return(n);
}
void inorder(Node *n)
{
	if (n == NULL)  return;
    
	inorder(n->left);
    printf("%d ", n->data);
	inorder(n->right);
}
void storeInorder(Node *n, int inorder[], int *index_ptr)
{
	if (n == NULL)
		return;

	storeInorder(n->left, inorder, index_ptr);
	inorder[*index_ptr] = n->data;
	(*index_ptr)++; // increase index for next entry
	storeInorder(n->right, inorder, index_ptr);
}
Node *sortedArrayToBST(int arr[], int start, int end)
{
	if (start > end)
	    return NULL;

	int mid = (start + end)/2;
	Node *root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start, mid-1);
	root->right = sortedArrayToBST(arr, mid+1, end);
	return root;
}
Node *mergeTrees(Node *root1, Node *root2, int m, int n)
{
	int arr1[m];
	int i = 0;
	storeInorder(root1, arr1, &i);
	
	int arr2[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	int *mergedArr = merge(arr1, arr2, m, n);
	return sortedArrayToBST (mergedArr, 0, m+n-1);
}
struct rbNode *root = NULL;

struct rbNode *createNode(int data) 
{
  struct rbNode *newnode;
  newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
  newnode->data = data;
  newnode->color = RED;
  newnode->link[0] = newnode->link[1] = NULL;
  return newnode;
}
void insertion(int data) 
{
  struct rbNode *stack[98], *ptr, *newnode, *xPtr, *yPtr;
  int dir[98], ht = 0, index;
  ptr = root;
  if (!root) {
    root = createNode(data);
    return;
  }

  stack[ht] = root;
  dir[ht++] = 0;
  while (ptr != NULL) {
    if (ptr->data == data) {
      printf("Duplicates Not Allowed!!\n");
      return;
    }
    index = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    ptr = ptr->link[index];
    dir[ht++] = index;
  }
  stack[ht - 1]->link[index] = newnode = createNode(data);
  while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
    if (dir[ht - 2] == 0) {
      yPtr = stack[ht - 2]->link[1];
      if (yPtr != NULL && yPtr->color == RED) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 0) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[1];
          xPtr->link[1] = yPtr->link[0];
          yPtr->link[0] = xPtr;
          stack[ht - 2]->link[0] = yPtr;
        }
        xPtr = stack[ht - 2];
        xPtr->color = RED;
        yPtr->color = BLACK;
        xPtr->link[0] = yPtr->link[1];
        yPtr->link[1] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    } else {
      yPtr = stack[ht - 2]->link[0];
      if ((yPtr != NULL) && (yPtr->color == RED)) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 1) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[0];
          xPtr->link[0] = yPtr->link[1];
          yPtr->link[1] = xPtr;
          stack[ht - 2]->link[1] = yPtr;
        }
        xPtr = stack[ht - 2];
        yPtr->color = BLACK;
        xPtr->color = RED;
        xPtr->link[1] = yPtr->link[0];
        yPtr->link[0] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    }
  }
  root->color = BLACK;
}
void inorderTraversal(struct rbNode *node) 
{
    if (node) 
    {
        inorderTraversal(node->link[0]);
        printf("%d  ", node->data);
        inorderTraversal(node->link[1]);
    }
}
int main()
{
    printf("\n PROGRAM 1\n");
    // T1 AVL Tree
	  Node *root1 = newNode(9);
	  root1->left		 = newNode(8);
	  root1->right	 = newNode(7);

	  // T2 AVL  Tree 
	  Node *root2 = newNode(20);
	  root2->left		 = newNode(15);
	  root2->right	 = newNode(10);

	  Node *mergedTree = mergeTrees(root1, root2, 3, 3);
	  printf ("Following is Inorder traversal of the merged tree \n");
	  inorder(mergedTree);
    printf("\n");

    printf("\n PROGRAM 2\n");
    insertion(41); insertion(38); insertion(31);
    insertion(12); insertion(19); insertion(8);
    
    printf("\n Inorder traversal of R-B tree\n");
    inorderTraversal(root);
    printf("\n");
	  return 0;
}