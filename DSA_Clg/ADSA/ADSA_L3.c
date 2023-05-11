#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;  
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;   
    return newNode;
}
Node *LevelOrderBST(Node *root , int data)//Q1
{
    if(root==NULL)
    {
        root = createNode(data);
        return root;
    }

    if(data <= root->data)
        root->left = LevelOrderBST(root->left, data);
    else
        root->right = LevelOrderBST(root->right, data);
    return root;    
}
Node *constructBst(int arr[], int n)//Q1,3
{
    if(n==0)
        return NULL;
    
    Node *root =NULL;
 
    for(int i=0;i<n;i++){
        root = LevelOrderBST(root , arr[i]);
    }

    return root;
}
void inorderTraversal(Node *root)
{
    if (root== NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data) ;
    inorderTraversal(root->right);   
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int extNodes(Node *root)//Q1
{
    if(root == NULL)       
        return 0;
    if(root->left == NULL && root->right==NULL)      
        return 1;            
    else 
        return extNodes(root->left) + extNodes(root->right);      
}
int intNodes(Node *root)//Q1
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + intNodes(root->left) + intNodes(root->right);
}

int getMaxInRadix(int arr[], int n)//Q2
{ 
    int max = arr[0];    
    for (int i = 1; i < n; i++){
        if (arr[i] > max)      
            max = arr[i];
    }
    return max;
}
void countSortRadix(int arr[], int n, int ij)//Q2
{
    int op[n];
    int i, c[10] = {0};
    for (i = 0; i < n; i++){
        c[ (arr[i]/ij)%10 ]++;
    }
    for (i = 1; i < 10; i++){
        c[i] += c[i - 1];
    }
    for (i = n - 1; i >= 0; i--){
        op[c[ (arr[i]/ij)%10 ] - 1] = arr[i];
        c[ (arr[i]/ij)%10 ]--;
    }
    for (i = 0; i < n; i++){
        arr[i] = op[i];
    }
}
void RadixSort(int arr[], int n)//Q2
{
    int m = getMaxInRadix(arr, n);
    for (int ij = 1; m/ij > 0; ij *= 10)
    {
        countSortRadix(arr, n, ij);
    }
}
void printArr(int arr[], int n)//Q2
{
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);               
    }
    printf("\n");
}
int findMaxBST(Node *root)//Q3
{
    if (root == NULL)
        return -99;
    int res = root->data;
    int lres = findMaxBST(root->left);
    int rres = findMaxBST(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
Node *minValBnode(Node *root)//Q3
{
    Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
Node *deleteBnode(Node* root, int key)//Q3
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteBnode(root->left, key);
    else if (key > root->data)
        root->right = deleteBnode(root->right, key);
    else{
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValBnode(root->right);
        root->data = temp->data;
        root->right = deleteBnode(root->right, temp->data);
    }
    return root;
}
Node *delRoot(Node *root)//Q3
{
    if (root == NULL)
        return root;
    int k = findMaxBST(root->left);
    root = deleteBnode(root,k);
    root->data = k;
    return root;
}
int heightBT(Node* root)//Q3-c
{
    if (root == NULL){return 0;}
    int left_tree = heightBT(root->left);
    int right_tree = heightBT(root->right);
    if (left_tree > right_tree){return left_tree + 1;}
    else{return right_tree + 1;}
}
int balanceBT(Node *root)//Q3-c
{
    if (root)
        return heightBT(root->left) - heightBT(root->right);
}
int labelFacBST(Node *root)//Q3-c
{
    if (root)
	{
        int f = labelFacBST(root->left);
        printf("Element - %d, Balance Factor - %d\n", root->data, balanceBT(root));
        int s = labelFacBST(root->right);
        if (f == -1 || s == -1)
            return -1;
        else if(balanceBT(root) >= 2 || balanceBT(root) <= -2)
            return -1;
        
        return 1;
    }
}
int main()
{
    printf("\n PROGRAM 1\n");
    int arr1[] = {10,20,50,30,60,80,35,45,77,90,95,98,67,88};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *root = constructBst(arr1, n);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Number of external nodes are %d \n", extNodes(root));
    printf("Number of internal nodes are %d \n", intNodes(root));
    printf("\n");

    printf("\n PROGRAM 2\n");
    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};   
    n = sizeof(arr2)/sizeof(arr2[0]);
    printf("Before Sorting -->   ");
    printArr(arr2, n);
    RadixSort(arr2, n);
    printf("After Sorting -->   ");
    printArr(arr2, n);
    printf("\n");

    printf("\n PROGRAM 3\n");
    int arr3[] = {5,3,10,2,4,7,11,1,6,9,12,8};
    n = sizeof(arr3)/sizeof(arr3[0]);
    Node *root1 = constructBst(arr3, n);
    printf("Inorder Traversal: ");
    inorderTraversal(root1);
    printf("\n\n");
    root1 = delRoot(root1);
    printf("Inorder Traversal After deleting root: ");
    inorderTraversal(root1);
    printf("\n");
    printf("Postorder Traversal After deleting root: ");
    postorderTraversal(root1);
    printf("\n");
    printf("Preorder Traversal After deleting root: ");
    preorderTraversal(root1);
    printf("\n\n");

    int isBal = labelFacBST(root1);
    if(isBal)
        printf("\nThe new tree is balanced\n");
    else
        printf("\nThe new tree is NOT balanced\n");
    printf("\n");
    return 0;
}