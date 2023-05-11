#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node *createNode(int value)
{
    struct node* newNode  = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void inorderTraversal(struct node *root) 
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}


int max(struct node *p)
{ 
    int mx = p->data; 
    if( p->left != NULL ) 
    { 
        int temp = max(p->left); 
        if( temp > mx ) mx = temp; 
    }
    if( p->right != NULL ) 
    { 
        int temp = max(p->right); 
        if( temp > mx ) mx = temp; 
    } 
    return mx; 
} 
int areIdentical(struct node *root1, struct node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;

	if (root1 == NULL || root2 == NULL)
		return 0;

	return (root1->data == root2->data && areIdentical(root1->left, root2->left) &&	areIdentical(root1->right, root2->right) );
}
int isIsomorphic(struct node *root1, struct node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;

	if (root1 == NULL || root2 == NULL)
		return 0;

	return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) );
}


int isSubtree(struct node *T, struct node *S)
{
	if (S == NULL)
		return 1;

	if (T == NULL)
		return 0;

	if (areIdentical(T, S))
		return 1;

	return isSubtree(T->left, S) || isSubtree(T->right, S);
}


void prog1()
{
    struct node *root = createNode(25);
    root->left = createNode(17);
    root->right = createNode(35);
    root->left->left = createNode(13);
    root->left->right = createNode(19);
    root->right->left = createNode(27);
    root->right->right = createNode(55);

    inorderTraversal(root);
    printf("\n");
    int m=max(root);
    printf("max no. = %d \n",m);
}
void prog2()
{
    struct node *root1, *root2, *root3, *root4;
    /*
             1                            
           /   \    
          2     7    
         / \     \               
        6   3     8
        ------------
        Binary tree 1
    */
    root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(7);
    root1->right->right = createNode(8);
    root1->left->right = createNode(3);
    root1->left->left = createNode(6);

    /*
             1                            
           /   \    
          7     2    
         /     / \               
        8     3   6
        ------------
        Binary tree 2
    */
    root2 = createNode(1);
    root2->left = createNode(7);
    root2->right = createNode(2);
    root2->right->right = createNode(6);
    root2->right->left = createNode(3);
    root2->left->left = createNode(8);

    /*
             1                            
           /   \    
          7     9    
         /     / \               
        8     3   6
        ------------
        Binary tree 3
    */
    root3 = createNode(1);
    root3->left = createNode(7);
    root3->right = createNode(9);
    root3->right->right = createNode(6);
    root3->right->left = createNode(3);
    root3->left->left = createNode(8);
    /*
             1                            
           /   \    
          2     7    
         / \     \               
        6   3     8
        ------------
        Binary tree 4
    */
    root4 = createNode(1);
    root4->left = createNode(2);
    root4->right = createNode(7);
    root4->right->right = createNode(8);
    root4->left->right = createNode(3);
    root4->left->left = createNode(6);

    if (isIsomorphic(root1, root2) == 1)
        printf("\n Tree1 and Tree2 is isomorphic");
    else
        printf("\n Tree1 and Tree2 is not isomorphic");
    
    if (isIsomorphic(root1, root4) == 1)
        printf("\n Tree1 and Tree4 is isomorphic");
    else
        printf("\n Tree1 and Tree4 is not isomorphic");
    
    if (isIsomorphic(root2, root3) == 1)
        printf("\n Tree2 and Tree3 is isomorphic");
    else
        printf("\n Tree2 and Tree3 is not isomorphic");
    
}

void mirror(struct node *root)
{
    if(root != NULL)
    {
        mirror(root->left);
        mirror(root->right);

        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

}
void prog3()
{
    struct node* root = createNode(2);
    root->left = createNode(7);
    root->right = createNode(5);
    root->left->right = createNode(6);
    root->left->right->left = createNode(1);
    root->left->right->right = createNode(11);
    root->right->right = createNode(9);
    root->right->right->left = createNode(4);
    printf("Inorder Traversal of Tree \n");
    inorderTraversal(root);
    printf("\n");

    mirror(root);
    printf("Inorder Traversal of Mirror Tree \n");
    inorderTraversal(root);
    printf("\n");
}
void prog4()
{
    struct node *T	 = createNode(26);
	T->right = createNode(3);
	T->right->right	 = createNode(3);
	T->left	= createNode(10);
	T->left->left = createNode(4);
	T->left->left->right = createNode(30);
	T->left->right = createNode(6);
    printf("Inorder Traversal of Tree T\n");
    inorderTraversal(T);
    printf("\n");
	
	struct node *S = createNode(10);
	S->right = createNode(6);
	S->left	= createNode(4);
	S->left->right = createNode(30);
    printf("Inorder Traversal of Tree S\n");
    inorderTraversal(S);
    printf("\n");

	if (isSubtree(T, S))
		printf("Tree 2 is subtree of Tree 1");
	else
		printf("Tree 2 is not a subtree of Tree 1");

	getchar();

}

int main()
{
    printf("\n---Program 1---\n");
    prog1();
    printf("\n");

    printf("\n---Program 2---\n");
    prog2();
    printf("\n");

    printf("\n---Program 3---\n");
    prog3();
    printf("\n");
    
    printf("\n---Program 4---\n");
    prog4();
    printf("\n");

    return 0;
}