//Deepest left leaf node in a binary tree
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
struct tree {
int data;
struct tree* left;
struct tree* right;
};

struct tree* newNode(int data){
struct tree* node=(struct  tree*)malloc(sizeof(struct tree*));
node->data=data;
node->left=NULL;
node->right=NULL;
};

void deepestLeftNode(struct tree* root, int level, bool isleft,int &max_l,int &val){
      if(root==NULL) return;
      if(isleft&&!root->left&&!root->right&&max_l<level){
            max_l=level;
            val=root->data;
            return;
      }
      deepestLeftNode(root->left,level+1,1,max_l,val);
      deepestLeftNode(root->right,level+1,0,max_l,val);
}

int deepestLeftLeaf(struct tree* root){
    int max_l=0,val=0;
    deepestLeftNode(root,0,1,max_l,val);
    return val;
}

int main()
{
    tree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->left->right->left->left=newNode(11);
    root->right->right->right->right = newNode(10);

    int result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result;
    else
        cout << "There is no left leaf in the given tree";

    return 0;
}
