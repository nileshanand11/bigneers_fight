///print diagonally of a binary tree
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>

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

queue<struct tree*>q;

void print_diagonally(struct tree* root){

if(root==NULL) return;
int sz=0;
struct tree* temp;
q.push(root);
//printf("%d ",root->data);
while(!q.empty()){
        sz=q.size();
    while(sz--){
        temp=q.front();
        q.pop();
        while(temp){
        printf("%d ",temp->data);
        if(temp->left) q.push(temp->left);
        temp=temp->right;
        }
    }
  }
}

int main(){
    tree* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/

    print_diagonally(root);

    return 0;

}
