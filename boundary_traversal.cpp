//http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
///boundary_traversal
#include<bits/stdc++.h>

using namespace std;

struct tree{
int data;
struct tree* left;
struct tree* right;
};

struct tree* newNode(int data){
tree* node=(tree*)malloc(sizeof(struct tree));
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
};

void print_leaf(tree* root){
if(!root) return;
print_leaf(root->left);
if(root->left==NULL&&root->right==NULL)
    printf("%d ",root->data);
print_leaf(root->right);
}

void print_left(tree* root){
if(!root) return;
if(root->left){
    printf("%d ",root->data);
    print_left(root->left);
    }
else if(root->right){
    printf("%d ",root->data);
    print_left(root->right);
    }
}

void print_right(tree* root){
if(!root) return;
if(root->left){
    print_right(root->left);
    printf("%d ",root->data);
    }
else if(root->right){
    print_right(root->right);
    printf("%d ",root->data);
    }
}
void print_boundary(tree* root){
if(!root) return;
printf("%d ",root->data);
//cout<<"\nleft ";
print_left(root->left);
//cout<<"\nleaf ";
print_leaf(root);
//cout<<"\nright ";
print_right(root->right);
}

int main(){
    tree* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->right->left=newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
   // boundary_traversal(root);
   print_boundary(root);
}
