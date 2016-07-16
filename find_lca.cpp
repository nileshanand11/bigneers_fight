// lca_recursive and iterative
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;
struct tree {
int data;
struct tree* left;
struct tree* right;
};

struct tree* newNode(int data){
struct tree* node= (struct tree*)malloc(sizeof(struct tree));
node->data=data;
node->left=NULL;
node->right=NULL;

return node;
};

struct tree* find_lca(struct tree * root , struct tree* p, struct tree* q){
if(q==NULL) return p;
if (p==NULL) return q;

if (!root || p==root || q==root) return root;
struct tree* llca = find_lca( root->left, p , q);
struct tree* rlca = find_lca( root->right,p, q);

if (llca && rlca) return root;
else if (llca) return llca;
else return rlca;
};

void inOrder(struct tree* root){
    if(root==NULL) return ;
    if (root->left) inOrder(root->left);
    cout << root->data<<" ";
    if (root->right) inOrder(root->right);
}

int main(){

struct tree* root ;
root=newNode(20);
root->left=newNode(8);
root->right=newNode(22);
root->left->left=newNode(4);
root->left->right=newNode(12);
root->left->left->left=newNode(13);
root->left->right->left=newNode(10);

inOrder(root);
struct tree* n1= root->left->right;
struct tree* n2=NULL;// root->right;
struct tree *node=find_lca(root, n1,n2);
cout << endl;
cout << node->data;

}
