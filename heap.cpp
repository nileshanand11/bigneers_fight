//heapyfy
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<conio.h>

using namespace std;

int ar[]={6,7,8,5,12,4,9,2};
int length=sizeof(ar)/sizeof(ar[0]);

struct heap {
//int heap_type;
int elements;
int capacity;
int *arr;
};

struct heap *createHeap(int cnt){
struct heap *h=(struct heap*)malloc(sizeof(struct heap));
    if(h==NULL) {
        printf("Memory Error");
        return h;
    }
    h->elements=0;
    h->capacity=cnt;
    h->arr=(int*)malloc(sizeof(int)*h->capacity);
    if ( h->arr == NULL) {
        printf("Memory errro");
        return h;
    }
    return h;
}


void heapyfy_down(int i,int hsize){
    cout<< "heapyfy_down call"<<endl;
    int maxv,temp;
    int l =2*i+1;
    int r =2*i+2;
    if (ar[i]<ar[l]&&l<=hsize)
        maxv = l;
    else
        maxv=i;
    if(ar[maxv] < ar[r] && r<=hsize)
        maxv=r;
    //swap maxv with i;
    if (maxv!=i){
        temp=ar[i];
        ar[i]=ar[maxv];
        ar[maxv]=temp;
        heapyfy_down(maxv,hsize);
    }

}

void buildHeap(int capacity){
    int i;
    //capacity=length-1;
    for(i=(capacity-1)/2;i>=0;i--)
    {
        cout<<"heapyfying "<< ar[i] << endl;
        heapyfy_down(i,capacity);

    }
}

void heapSort(){
    buildHeap(length-1);
        for(int j=0;j<length;j++)
        cout<< ar[j] << " ";
    cout<<endl;
    int temp,hs,i;
    hs=length-1;
    for(i=hs;i>=0;i--){
            cout<< "ar[i] "<<ar[i]<<endl;
        temp=ar[i];
        ar[i]=ar[0];
        ar[0]=temp;
        hs--;
        heapyfy_down(0,hs);
    }
    for(int j=0;j<length;j++)
        cout<< ar[j] << " ";
    cout<<endl;
}

int main()
{

    heapSort();
    cout<<endl;
    getch();
}
