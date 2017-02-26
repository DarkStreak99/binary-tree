/*Program to design, develop and execute a program in C++ to create a class called BIN_TREE
 (Binary tree) with member functions to perform inorder, preorder and postorder traversals.*/

#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
struct node
{
int info;
struct node *left;
struct node *right;
};
typedef struct node tree ;
tree *root=NULL;
class BIN
{
int num;
tree *p,*prev,*temp;
public:
void insert();
void inorder(tree *);
void postorder(tree *);
void preorder(tree *);
void display();
};
void BIN:: insert()
{
p=new(tree);
cout<<"\n Enter number:";
cin>>num;
p->info=num;
p->left=p->right=NULL;
if(root==NULL)
{
root=p;
return;
}
temp=root;
while(temp!=NULL)
{
if(num>=temp->info)
{
prev=temp;
temp=temp->right;
}
else
{
prev=temp;
temp=temp->left;
}
}
if(num>=prev->info)
prev->right=p;
else
prev->left=p;
}
void BIN::preorder(tree *temp)
{
if(temp!=NULL)
{
cout<<"\t"<<temp->info;
preorder(temp->left);
preorder(temp->right);
}
}
void BIN:: inorder(tree *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
cout<<"\t"<<temp->info;
inorder(temp->right);
}
}
void BIN::postorder(tree *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
cout<<"\t"<<temp->info;
}
}
void BIN:: display()
{
if(root==NULL)
{
cout<<"\n ***EMPTY TREE**** \n";
return;
}
cout<<"\n\n THE PREORDER DISPLAY IS: ";
preorder(root);
cout<<"\n\n THE INORDER DISPLAY IS: ";
inorder(root);
cout<<"\n\n THE POSTORDER DISPLAY IS: ";
postorder(root);
}
int main()
{
BIN o;
int ch=1, count=0;
clrscr();
while(ch)
{
cout<<"\n\n\n\t\t\t***********MENU************\n";
cout<<"\n\t\t\t1:INSERT-IN-TREE\n\t\t\t2:DISPLAY\n\t\t\t3.QUIT\n";
cout<<"\nEnter your choice:\n";
cin>>ch;
switch(ch)
{
case 1:system("clear");
count++;
o.insert();
break;
case 2:system("clear");
cout<<"\n\n THE NUMBER OF NODES IN THE BST is "<< count;
o.display();
break;
case 3:exit(0);
}
}
return 0;
}
