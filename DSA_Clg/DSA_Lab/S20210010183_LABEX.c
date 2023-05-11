#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->key = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void inorder(struct node *root)
{
    if (root == NULL) 
        return;

    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
}
struct node *insert(struct node *node, int key)
{
    if(node==NULL)
        return newNode(key);
    else if(key>node->key)
        node->right = insert(node->right, key);
    else 
        node->left = insert(node->left,key);
    return node;
}

void rv(struct node *root, int l,int *ml)
{
    if (root==NULL)
        return;
  
    if (*ml < l){
        printf("%d  ", root->key);
        *ml = l;
    }
    rv(root->right, l+1, ml);
    rv(root->left, l+1, ml);

}
void rightView(struct node *root){
    int ml = 0;
    rv(root, 1, &ml);
}

void tt(struct node *root, int *s)
{
   if (root == NULL)
    return;

   tt(root->right, s);
   *s = *s + root->key;
   root->key = *s - root->key;
   tt(root->left, s);
}
void transformTree(struct node *root){
    int s = 0;
    tt(root, &s);
}

void sortOddEven(int a[],int n)
{
    for (int x = 2; x < n; x++)
    {
        int y = x-2;
        int t = a[x];

        if ((x+1) & 1 == 1){
            while (t >= a[y] && y >= 0)
            {
                a[y+2] = a[y];
                y -= 2;
            }
            a[y+2] = t;           
        }
        else{
            while (t <= a[y] && y >= 0)
            {
                a[y+2] = a[y];
                y -= 2;
            }
            a[y+2] = t;  
        }
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root,50);
    insert(root,30); insert(root, 20); insert(root,40); 
    insert(root, 70); insert(root,60); insert(root,80);

    inorder(root);  printf("\n");

    rightView(root);    printf("\n");

    transformTree(root);
    inorder(root);  printf("\n");

    int n = 9;
    int a[] = {7,10,11,3,6,9,2,13,0};
    sortOddEven(a,n);
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    return 0;
}