/// spiral order traversal of binary tree via recursion
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct tree{
int data;
struct tree* left;
struct tree* right;
};

struct tree* newNode(int data){
struct tree* node =(struct tree*)malloc(sizeof(struct tree));
node->data=data;
node->left=NULL;
node->right=NULL;
};

int height(struct tree* root){
if(root==NULL) return 0;
int lh=height(root->left);
int rh=height(root->right);

return (lh>rh?lh:rh)+1;
}
void printLevelOrder(struct tree* root, int level,bool r2l){
    if(level==1) {printf("%d",root->data);
    return ;}
    if(r2l){
        printLevelOrder(root->left,level-1,r2l);
        printLevelOrder(root->right,level-1,r2l);}
    else
    {
        printLevelOrder(root->right,level-1,r2l);
        printLevelOrder(root->left,level-1,r2l);
    }
}

void levelOrderZig( struct tree* root){
int h=height(root);
bool c=1;
for (int i=1;i<=h;i++)
    {
        c=!c;
        printf("\nc: %d\n",c);
        printLevelOrder(root,i,c);}
}


int main(){
    struct tree* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    levelOrderZig(root);
    return 0;
}
