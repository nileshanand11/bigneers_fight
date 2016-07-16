#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<queue>
using namespace std;
struct tree {
int data;
struct tree *left=NULL;
struct tree *right=NULL;
};
tree* newNode(int data)
{
    tree *temp = new tree;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void printGivenLevel(struct tree* root, int level);
int get_height(struct tree* root){
if(root==NULL) return 0;
int lh=get_height(root->left);
int rh=get_height(root->right);
return lh>rh?lh+1:rh+1;
}

void print_level_tree(struct tree* root){
int h = get_height(root);
cout << "H :" << h <<endl;
int lvl;
if(h%2==0)   lvl=h-1;
else         lvl=h;
//cout<< root->data;
cout << "L :" << lvl <<endl;
printGivenLevel(root,lvl);

}
void printGivenLevel(struct tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {if(root->left==NULL && root->right==NULL)
        printf("%d ", root->data);}
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int main(){
    tree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right=newNode(7);
    root->right->left->right->left=newNode(9);
    root->right->right->right=newNode(8);
    root->right->right->right->right=newNode(10);
    root->right->right->right->right->left=newNode(11);
    print_level_tree(root);

}
