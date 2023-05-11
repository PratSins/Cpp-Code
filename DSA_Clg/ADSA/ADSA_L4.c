#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode
{
	int data;
	struct Bnode *left;
	struct Bnode *right;
	int height;
} Node;

int max(int x, int y){
	return (x > y)? x : y;
}
int getHeight(Node *tn)
{
	if (tn == NULL)
		return 0;
	return tn->height;
}
Node *createNode(int data)
{
	Node* root = (Node*)malloc(sizeof(Node));

	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;

	return root;
}
Node *rightRotate(Node *b)
{
	Node *a = b->left;
	Node *tpm = a->right;
	a->right = b;
	b->left = tpm;
	b->height = max(getHeight(b->left), getHeight(b->right))+1;
	a->height = max(getHeight(a->left), getHeight(a->right))+1;
	return a;
}
Node *leftRotate(Node *a)
{
	Node *b = a->right;
	Node *tpm = b->left;
	b->left = a;
	a->right = tpm;
	a->height = max(getHeight(a->left), getHeight(a->right))+1;
	b->height = max(getHeight(b->left), getHeight(b->right))+1;
	return b;
}
int getBalance(Node *tn){
	if (tn == NULL) return 0;
	return getHeight(tn->left) - getHeight(tn->right);
}
Node *insert(Node *root, int data)
{
	if (root == NULL)
		return createNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	else 
		return root;

	root->height = 1 + max(getHeight(root->left),getHeight(root->right));
	int bln = getBalance(root);

	if (bln > 1 && data < root->left->data)	{
		printf("LL Rotation\n");
		return rightRotate(root);
	}
	if (bln < -1 && data > root->right->data){
		printf("RR rotation\n");
		return leftRotate(root);
	}
	if (bln > 1 && data > root->left->data)	{
		printf("LR rotation\n");
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bln < -1 && data < root->right->data){
		printf("RL rotation\n");
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
Node *minvalNode(Node* nd)
{
	Node* curr = nd;
	while (curr->left != NULL) curr = curr->left;
	return curr;
}
Node* delNode(Node* root, int data)
{
	if (root == NULL)
		return root;

	if ( data < root->data )
		root->left = delNode(root->left, data);

	else if( data > root->data )
		root->right = delNode(root->right, data);

	else
	{
		if( (root->left == NULL) || (root->right == NULL) )
		{
			Node *tpm = root->left ? root->left :root->right;

			if (tpm == NULL)
			{
				tpm = root;
				root = NULL;
			}
			else
			*root = *tpm;
			free(tpm);
		}
		else
		{
			Node* tpm = minvalNode(root->right);
			root->data = tpm->data;
			root->right = delNode(root->right, tpm->data);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(getHeight(root->left),getHeight(root->right));

	int bln = getBalance(root);

	if (bln > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (bln > 1 && getBalance(root->left) < 0)	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (bln < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (bln < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void inOrder(Node *root)
{
	if(root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}
int main()
{
	printf("\n-----Q1------\n");
	Node *root = NULL;
	root = insert(root, 12);
	root = insert(root, 14);
	root = insert(root, 15);
	root = insert(root, 17);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 20);

	printf("\nInorder traversal of the constructed AVL tree is \n");
	inOrder(root);
	
	printf("\n\n-----Q2-----");
	printf("\nDeleting the entire tree starting with the root node (inorder traversal) ...\n");

	root = delNode(root, 12);
	inOrder(root);
	printf("\n");
	root = delNode(root, 14);
	inOrder(root);
	printf("\n");
	root = delNode(root, 15);
	inOrder(root);
	printf("\n");
	root = delNode(root, 17);
	inOrder(root);
	printf("\n");
	root = delNode(root, 3);
	inOrder(root);
	printf("\n");
	root = delNode(root, 4);
	inOrder(root);
	printf("\n");
	root = delNode(root, 9);
	inOrder(root);
	printf("\n");
	root = delNode(root, 10);
	inOrder(root);
	printf("\n");
	root = delNode(root, 20);
	inOrder(root);

	printf("\n\n");
	return 0;
}