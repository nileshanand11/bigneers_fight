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
struct tree *nextr=NULL;
};
tree* newNode(int data)
{
    tree *temp = new tree;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printLevelOrder(struct tree *root){
if (root==NULL) return;
struct tree *p = root;
struct tree* temp;
int s=0;
queue <tree *> q;
q.push(p);
while (!q.empty()){
    s=q.size();
    while (s){
        temp=q.front();
        q.pop();
        cout<< temp->data<<" ";
        if(s>1)
        temp->nextr=q.front();

        if (temp->left)
        q.push(temp->left);
        if (temp->right)
        q.push(temp->right);
        s--;
    }
    cout<<endl;
    }
}

int height_tree(struct tree* root){
if(root==NULL) return 0;
int lh=height_tree(root->left);
int rh=height_tree(root->right);
return lh>rh?lh+1:rh+1 ;
}

int main(){
        // Let us create binary tree shown in above diagram
    tree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    printLevelOrder(root);
   // cout << root->left->left->nextr->data <<endl;
   // struct tree* p=root->left->nextr;
   // cout << p->data;
int height=height_tree(root);
cout << "H " << height << endl;
    return 0;

}
