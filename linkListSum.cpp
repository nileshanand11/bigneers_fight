/// sum of the link list.
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

struct node{
int data;
struct node *next;
};

void newNode(struct node** head, int data){
struct node* nnode=(struct node*)malloc(sizeof(struct node));
nnode->data=data;
nnode->next=*head;
*head=nnode;
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

node* addSum(struct node* h1,struct node* h2,int &carry ){
if(h1==NULL) return h1;
node* resultS=(node*)malloc(sizeof(struct node));
resultS->next=addSum(h1->next,h2->next,carry);
//printf("h1 %d  h2 %d \n",h1->data,h2->data);
int sum=h1->data+h2->data+carry;
carry=sum/10;
sum%=10;
resultS->data=sum;
return resultS;
}

 void addRestCarry(struct node* h1, struct node* cur, int &carry, struct node** res){
 int sum=0;
 if(h1!= cur){
  addRestCarry(h1->next,cur,carry,res);
  sum=h1->data+carry;
  carry=sum/10;
  sum=sum%10;
  newNode(res,sum);
 }
 }
void addList(struct node* head1,struct node* head2, struct node** result){
int s1=0,s2=0,carry=0,diff=0;
struct node *p=head1,*q=head2,*temp;
while(p){
    s1+=1; p=p->next;
}
while(q){
    s2+=1; q=q->next;
}
//printf("s1:%d , s2:%d\n",s1,s2);
if(s1==s2){
    *result=addSum(head1,head2,carry);
}
else if(s1!=s2){
        if(s1<s2) {temp=head1;head1=head2;head2=temp;}
        diff=abs(s1-s2);
        //printf("diff: %d\n",diff);
        p=head1;q=head2;
        while(diff--)p=p->next;
        *result=addSum(p,head2,carry);
     //   cout<<endl;
      //  printList(*result);
         addRestCarry(head1,p,carry,result);
}

if(carry)
newNode(result,carry);
};


int main()
{
    node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = {9, 3, 4};
    int arr2[] = {1,2,3,4};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create first list as 9->9->9
    int i;
    for (i = size1-1; i >= 0; --i)
        newNode(&head1, arr1[i]);

    // Create second list as 1->8
    for (i = size2-1; i >= 0; --i)
        newNode(&head2, arr2[i]);
    printList(head1);
    printList(head2);
    addList(head1, head2, &result);
    printList(result);

    return 0;
}
