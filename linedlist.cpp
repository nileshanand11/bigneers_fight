// doubly link list
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct node {
int data;
struct node * prv;
struct node * nxt;
};

void push(struct node ** head, int val){
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->prv=NULL;
newnode->nxt=(*head);
if((*head)!=NULL)
(*head)->prv=newnode;
(*head)= newnode;

}

void display(struct node * head){
struct node *p=head;
cout<<"display : ";
while(p){
    printf("%d ",p->data);
    p=p->nxt;
    }
    cout<<endl;
}


struct node* reverse_ddl(struct node * head){

if(head==NULL) return NULL;
if (head->nxt==NULL) return head;

struct node* nxtElm;
nxtElm=(head->nxt);
head->nxt=NULL;
struct node* q = reverse_ddl(nxtElm);
nxtElm->nxt=head;
return q;
}
struct node* reverse_ddl_itr(struct node* head){
if (head==NULL) return NULL;
if (head->nxt==NULL) return head;
struct node* cur = head;
struct node *temp=NULL, *nxtNode=NULL;
int i=5;
while (cur){
    cout<<cur->data<<" ";
    nxtNode =cur->nxt;
    cur->nxt=temp;
    temp=cur;
    cur=nxtNode;
}
return temp;

}


int main(){
  struct node* head = NULL;
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
  display(head);
  head=reverse_ddl(head);
  display(head);
  head=reverse_ddl_itr(head);
  display(head);

}
