///left leaf odd level node
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
struct tree {
int data;
struct tree* left;
struct tree* right;
};

struct tree* newNode(int data){
struct tree* node=(struct tree*)malloc(sizeof(struct tree));
node->data=data;
node->left=NULL;
node->right=NULL;
};


void left_leaf_odd(struct tree* root,int level, int &mlevel, int &mleft,int lor){
if(root==NULL) return;
if(lor && !root->left && !root->right){
        printf("level %d and root %d\n",level,root->data);
    if(level>mlevel && level&1){
        mlevel=level;
        mleft=root->data;
    }
}
left_leaf_odd(root->left,level+1,mlevel,mleft,1);
left_leaf_odd(root->right,level+1,mlevel,mleft,0);

}

int deepestLeftLeaf(struct tree* root){
if (root==NULL) return -1;
int result=-1,mlevel=-1;
left_leaf_odd(root,1,mlevel,result,1);
return result;
}

int main(){
    tree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
   // root->right->left->right->left = newNode(9);
    //root->right->left->right->left->left=newNode(11);
    root->right->right->right->right = newNode(10);

    int result = deepestLeftLeaf(root);
    if (result)
        //cout << "The deepest left child is " << result;
        printf("%d ", result);
    else
        cout << "There is no left leaf in the given tree";

    return 0;


}

