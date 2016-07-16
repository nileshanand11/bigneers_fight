///function to find the kth node from the end
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
struct node{
int data;
struct node* next;
};

void push(struct node **head, int data){
struct node *n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->next=*head;
*head=n;
}
void make_loop(struct node *head){
struct node *p=head,*q=head;
int c=0;
while(p->next) p=p->next;
while(q->next) {if(++c == 3) break; q=q->next;}
p->next=q;
}

void display(struct node *head){
while(head){
    cout << head->data << " ";
    head=head->next;
    }
}

bool is_loop(struct node *head){
    struct node *fptr,*sptr;
    if(head == NULL || head->next == NULL) return 0;
    fptr=head; sptr=head;
    while(fptr){
        fptr=fptr->next;
        if(fptr==sptr)return 1;
        if(fptr==NULL) return 0;
        fptr=fptr->next;
        if(fptr==sptr)return 1;
        sptr=sptr->next;
    }
    return 0;
}
struct node* loop_node(struct node * head){
    struct node *sptr=head,*fptr=head;
    while(fptr){
        sptr=sptr->next;
        fptr=fptr->next->next;
        if(fptr==sptr) break;
    }
    return sptr;
};
struct node* loop_merge_point(struct node* head, struct node* ptr){
    struct node *sp=head, *fp=ptr;
    while(sp!=fp){
        sp=sp->next;
        fp=fp->next;
    }
return sp;
};
int loop_length(struct node *head){
     struct node *sptr=head,*fptr=head;
    while(fptr){
        sptr=sptr->next;
        fptr=fptr->next->next;
        if(fptr==sptr) break;
    }
    sptr=sptr->next;
    int c=1;
    while(sptr!=fptr){
        ++c;
        sptr=sptr->next;
    }
    return c;
}
int merge_length(struct node *head,struct node* mn){
        struct node *sptr=head,*fptr=mn;
        int len=0;
        while(sptr!=fptr){
                sptr=sptr->next;
                len++;
                }
return len;
}

int main(){
     struct node* head = NULL;
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
     display(head);
     make_loop(head);
     cout<<endl;
     int val = is_loop(head);
     if (val){
        struct node* lpnode=loop_node(head);
       // cout<< "loop node " << lpnode->data<<endl;
        struct node* mnode=loop_merge_point(head,lpnode);
        //cout << "merge point "<< mnode->data << endl;
        int loop_len=loop_length(head);
        int mlen=merge_length(head,mnode);
        int list_length=merge_length(head,mnode)+loop_len;
        int k=4;
        struct node * cur=head;
        for (int i=0;i<(list_length-k);i++){
            cur=cur->next;
        }
            cout <<cur->data;
        }
        else {cout << "loop not found";}
        return 0;
}

