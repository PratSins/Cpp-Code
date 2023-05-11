#include <stdio.h>
#include <stdlib.h>

enum nodeColor {
  RED,
  BLACK
};

struct rbNode {
  int data, color;
  struct rbNode *link[2];
};

struct rbNode *root = NULL;

// Create a red-black tree
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
    while (ptr != NULL) 
    {
        if (ptr->data == data) 
        {
            printf("Duplicates Not Allowed!!\n");
            return;
        }
        index = (data - ptr->data) > 0 ? 1 : 0;
        stack[ht] = ptr;
        ptr = ptr->link[index];
        dir[ht++] = index;
    }

    stack[ht - 1]->link[index] = newnode = createNode(data);
    while ((ht >= 3) && (stack[ht - 1]->color == RED)) 
    {
        if (dir[ht - 2] == 0) 
        {
            yPtr = stack[ht - 2]->link[1];
            if (yPtr != NULL && yPtr->color == RED) 
            {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2;
            } 
            else 
            {
                if (dir[ht - 1] == 0) {
                    yPtr = stack[ht - 1];
                } 
                else 
                {
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
                } 
                else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        }
        else 
        {
            yPtr = stack[ht - 2]->link[0];
            if ((yPtr != NULL) && (yPtr->color == RED)) 
            {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2;
            } 
            else 
            {
                if (dir[ht - 1] == 1) {
                    yPtr = stack[ht - 1];
                } 
                else {
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
                } 
                else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        }
    }
    root->color = BLACK;
}

void deletion(int data)
{
    struct rbNode *stack[98], *ptr, *xPtr, *yPtr;
    struct rbNode *pPtr, *qPtr, *rPtr;
    int dir[98], ht = 0, diff, i;
    enum nodeColor color;

    if (!root) {
        printf("Tree not available\n");
        return;
    }

    ptr = root;
    while (ptr != NULL) 
    {
        if ((data - ptr->data) == 0)
            break;
        diff = (data - ptr->data) > 0 ? 1 : 0;
        stack[ht] = ptr;
        dir[ht++] = diff;
        ptr = ptr->link[diff];
    }

    if (ptr->link[1] == NULL) 
    {
        if ((ptr == root) && (ptr->link[0] == NULL)) {
            free(ptr);
            root = NULL;
        } 
        else if (ptr == root) 
        {
            root = ptr->link[0];
            free(ptr);
        } 
        else {
            stack[ht - 1]->link[dir[ht - 1]] = ptr->link[0];
        }
    } 
    else 
    {
        xPtr = ptr->link[1];
        if (xPtr->link[0] == NULL)
        {
            xPtr->link[0] = ptr->link[0];
            color = xPtr->color;
            xPtr->color = ptr->color;
            ptr->color = color;

            if (ptr == root) {
                root = xPtr;
            } 
            else {
                stack[ht - 1]->link[dir[ht - 1]] = xPtr;
            }

            dir[ht] = 1;
            stack[ht++] = xPtr;
        } 
        else {
            i = ht++;
            while (1)
            {
                dir[ht] = 0;
                stack[ht++] = xPtr;
                yPtr = xPtr->link[0];
                if (!yPtr->link[0])
                break;
                xPtr = yPtr;
            }

            dir[i] = 1;
            stack[i] = yPtr;
            if (i > 0)
                stack[i - 1]->link[dir[i - 1]] = yPtr;

            yPtr->link[0] = ptr->link[0];

            xPtr->link[0] = yPtr->link[1];
            yPtr->link[1] = ptr->link[1];

            if (ptr == root) {
                root = yPtr;
            }

            color = yPtr->color;
            yPtr->color = ptr->color;
            ptr->color = color;
        }
    }

    if (ht < 1)
        return;

    if (ptr->color == BLACK) 
    {
        while (1) 
        {
            pPtr = stack[ht - 1]->link[dir[ht - 1]];
            if (pPtr && pPtr->color == RED) {
                pPtr->color = BLACK;
                break;
            }

            if (ht < 2)
                break;

            if (dir[ht - 2] == 0) 
            {
                rPtr = stack[ht - 1]->link[1];

                if (!rPtr)
                    break;

                if (rPtr->color == RED) 
                {
                    stack[ht - 1]->color = RED;
                    rPtr->color = BLACK;
                    stack[ht - 1]->link[1] = rPtr->link[0];
                    rPtr->link[0] = stack[ht - 1];

                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    }
                     else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    dir[ht] = 0;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->link[1];
                }

                if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) && (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) 
                {
                    rPtr->color = RED;
                } 
                else 
                {
                    if (!rPtr->link[1] || rPtr->link[1]->color == BLACK) 
                    {
                        qPtr = rPtr->link[0];
                        rPtr->color = RED;
                        qPtr->color = BLACK;
                        rPtr->link[0] = qPtr->link[1];
                        qPtr->link[1] = rPtr;
                        rPtr = stack[ht - 1]->link[1] = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = BLACK;
                    rPtr->link[1]->color = BLACK;
                    stack[ht - 1]->link[1] = rPtr->link[0];
                    rPtr->link[0] = stack[ht - 1];
                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } 
                    else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    break;
                }
            } 
            else
            {
                rPtr = stack[ht - 1]->link[0];
                if (!rPtr)
                    break;

                if (rPtr->color == RED) 
                {
                    stack[ht - 1]->color = RED;
                    rPtr->color = BLACK;
                    stack[ht - 1]->link[0] = rPtr->link[1];
                    rPtr->link[1] = stack[ht - 1];

                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } 
                    else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    dir[ht] = 1;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->link[0];
                }
                if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) && (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) 
                {
                    rPtr->color = RED;
                } 
                else 
                {
                    if (!rPtr->link[0] || rPtr->link[0]->color == BLACK) 
                    {
                        qPtr = rPtr->link[1];
                        rPtr->color = RED;
                        qPtr->color = BLACK;
                        rPtr->link[1] = qPtr->link[0];
                        qPtr->link[0] = rPtr;
                        rPtr = stack[ht - 1]->link[0] = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = BLACK;
                    rPtr->link[0]->color = BLACK;
                    stack[ht - 1]->link[0] = rPtr->link[1];
                    rPtr->link[1] = stack[ht - 1];
                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } 
                    else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    break;
                }
            }
            ht--;
        }
    }
}

void inorderTraversal(struct rbNode *node) 
{
    if (node) {
        inorderTraversal(node->link[0]);
        printf("%d  ", node->data);
        inorderTraversal(node->link[1]);
    }
    return;
}

typedef struct node{
    int data;
    struct node* left;
    struct node* right;  
} Node;

Node *new_node(int x)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}
Node *insertBST(Node *root, int x)
{
    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right = insertBST(root->right, x);
    else
        root->left = insertBST(root->left,x);
    return root;
}
void inorderBST(Node *root)
{
    if(root!=NULL)
    {
        inorderBST(root->left);
        printf(" %d ", root->data);
        inorderBST(root->right);
    }
}
int printAncestors(Node *root, int target)
{
	if (root == NULL)
		return 0;
 
	if (root->data == target)
		return 1;
 
	if ( printAncestors(root->left, target)==1 || printAncestors(root->right, target)==1 )
	{
		printf("%d ", root->data);
		return 1;
	}
	return 0;
}
int main()
{
    printf("\n PROGRAM 1\n");
    insertion(41); insertion(38); insertion(31);
    insertion(12); insertion(19); insertion(8);
    
    printf("\nInorder traversal of R-B tree\n");
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 8\n");
    deletion(8);
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 12\n");
    deletion(12);
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 19\n");
    deletion(19);
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 31\n");
    deletion(31);
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 38\n");
    deletion(38);
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting RBNode 41\n");
    deletion(41);
    inorderTraversal(root);
    printf("\n");

    printf("\n");


    printf("\n PROGRAM 2\n");
    Node *root;
    root = new_node(20);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,15);
    insertBST(root,9);
    insertBST(root,7);
    insertBST(root,12);
    insertBST(root,30);
    insertBST(root,25);
    insertBST(root,40);
    insertBST(root, 45);
    insertBST(root, 42);

    inorderBST(root);

    int k;
    printf("\n\nEnter a Node value to search for its ancestors\n  ->");
    scanf("%d",&k);
    printf("Printing ancestors of Node %d\n", k);
    int b = printAncestors(root, k);
    printf("\n\n\n");

    return 0;
}