/// reverse the link list till kth node
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
int data;
struct node* next;
} ;

void display(struct node* head){
while(head){
    cout << head->data << " ";
    head=head->next;
}
}

struct node *push(struct node ** head,int data){
struct node *n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->next=*head;
*head=n;
return *head;
}

struct node *rlist(struct node *head){
if( head==NULL || head->next == NULL) return head;
struct node *prev=NULL, *cur=head, *nxt=NULL;
while (cur){
    nxt=cur->next;
    cur->next=prev;
    prev=cur;
    cur=nxt;
}
return prev;
};
struct node* rklist(struct node* head, int k){
if( head==NULL || head->next==NULL ) return head;
struct node *startn, *endn, *nextn;
nextn=head;
head=NULL;
struct node* ln;
while(nextn){
        startn=nextn;
        endn=nextn;
    for(int i=1;i<k;i++){
        endn=endn->next;
        if(endn==NULL) { cout << "break\n"; break;}
    }
    if (endn==NULL) nextn=NULL;
    else{
        nextn=endn->next;
        endn->next=NULL;}

        startn=rlist(startn);
    if(head==NULL){head=startn; ln=startn;}
    else { while(ln->next)
            ln=ln->next;
            ln->next=startn;
}
}
return head;
};


int main(){
struct node* head = NULL;

     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
  //   push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
     printf("\nGiven linked list \n");
     display(head);
     printf("\nfunction called \n");
     head = rklist(head, 10);

     printf("\nReversed Linked list \n");
     display(head);
     return(0);
}
