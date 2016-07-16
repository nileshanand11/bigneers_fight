///left most and right most node of binary tree
#include <bits/stdc++.h>

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
queue< tree*> q,ql;
void lr_view(struct tree* root){
if(!root) return;
q.push(root);
int cnt,sz;
tree *temp;
while(!q.empty()){
    cnt=q.size();
    sz=cnt;
    while(cnt){
        temp=q.front();
        q.pop();
        if(cnt==1|| cnt==sz){
            printf("%d ",temp->data);
        }
        if(temp->left) q.push(temp->left);
        if(temp->right)q.push(temp->right);
        cnt--;
        }
    }
}
stack<tree* > s;
void boundary_traversal(struct tree* root){
if(!root) return;
q.push(root);
int cnt,sz;
tree *temp;
while(!q.empty()){
    cnt=q.size();
    sz=cnt;
    while(cnt){
        temp=q.front();
        q.pop();
        if(cnt==sz)
            {
                printf("%d ",temp->data);
                if(temp->left==NULL&&temp->right==NULL) ql.push(temp)

        }
        else if( cnt==1) s.push(temp);
        if(temp->left) q.push(temp->left);
        if(temp->right)q.push(temp->right);
        cnt--;
        }
    }
cout<<endl;
while(!s.empty()){
    temp=s.top();
    s.pop();
    printf("%d ", temp->data);
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
    lr_view(root);
    cout<<endl;
    boundary_traversal(root);


}
