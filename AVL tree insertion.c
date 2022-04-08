#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node *left;
struct node *right;
int height;
};
int max(int a ,int b);
int height(struct node *Node)
{
int lh,rh;
if(Node==NULL)
return -1;
lh=height(Node->left);
rh=height(Node->right);
return max(lh,rh)+1;
}
int max(int a,int b)
{
return (a>b)?a:b;
}
int bf(struct node *Node)
{
if(Node==NULL)
return 0;
return height(Node->left)-height(Node->right);
}
struct node *CreateNew(int key)
{
struct node *Node=(struct node *)malloc(sizeof(struct node));
Node->key=key;
Node->left=NULL;
Node->right=NULL;
Node->height=0;
return Node;
}
struct node *leftRotate(struct node *x)
{
struct node *y=x->right;
struct node *T2=y->left;
y->left=x;
x->right=T2;
x->height=height(x);
y->height=height(y);
return y; // return newnode
}
struct node *rightRotate(struct node *y)
{
struct node *x=y->left;
struct node *T2=x->right;
x->right=y;
y->left=T2;
x->height=height(x);
y->height=height(y);
return x; //return newnode
}
struct node *insert(struct node *Node,int key)
{
int res;
if(Node==NULL)
return (CreateNew(key));
else if(key>Node->key)
Node->right=insert(Node->right,key);
else if(key<Node->key)
Node->left=insert(Node->left,key);
else
return Node; //equal keys are not allowed
Node->height=height(Node);
res=bf(Node);
if(res>1 && key<Node->left->key)
return rightRotate(Node);
if(res<-1 && key>Node->right->key)
return leftRotate(Node);
if(res>1 && key>Node->left->key)
{
Node->left=leftRotate(Node->left);
return rightRotate(Node);
}
if(res<-1 && key<Node->right->key)
{
Node->right=rightRotate(Node->right);
return leftRotate(Node);
}
return Node;
}
void preorder(struct node *root)
{
if(root==NULL)
return;
if(root!=NULL)
{
printf("%d ",root->key);
preorder(root->left);
preorder(root->right);
}
}
void main()
{
struct node *root=NULL;
root=insert(root,10);
root=insert(root,20);
root=insert(root,30);
root=insert(root,40);
root=insert(root,50);
root=insert(root,25);
printf("preorder traversal of tree:\n");
preorder(root);
}



