//level order with one level
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<iostream>

using namespace std;

struct tree {
int data;
struct tree *lchild;
struct tree *rchild;
};

queue<tree* >q;

//struct tree* p =(struct tree* )malloc(sizeof(struct tree));
struct  tree *newNode ( int val)
{
struct tree *node=(struct tree* )malloc(sizeof(struct tree));
node->data=val;
node->lchild=NULL;
node->rchild=NULL;
return node;
}
struct tree *p= newNode(NULL);

void display_level(struct tree *root){
    if (root->data==NULL)
    {cout << "ROOT is NULL "; return; }

     q.push(root);
     q.push(p);

     struct tree *temp;

     while (!q.empty()){
        temp=q.front();
        q.pop();

        if(temp->data!=NULL){
        cout<< temp->data<<" ";
        if(temp->lchild) q.push(temp->lchild);
        if(temp->rchild) q.push(temp->rchild);
        }
        else{
         cout<< endl;
         if(q.front()->lchild||q.front()->rchild)
         q.push(p);
        }
     }
}

int main(){
    p->data=NULL;
    struct tree *root = newNode(1);
    root->lchild        = newNode(2);
    root->rchild           = newNode(3);
    root->lchild->lchild  = newNode(4);
    root->lchild->rchild = newNode(5);
    root->rchild->lchild  = newNode(6);
    root->rchild->rchild = newNode(7);
    display_level(root);
}
