// smallest number
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int arr[]={1,2,4};

int find_missing(){
int l=0,len=sizeof(arr)/sizeof(arr[0]),h=len-1,m;
while (l<h){
    m=(l+h)/2;
    if(arr[m]==m){
        if(arr[m+1] != m+1) return m+1;
        else l=m+1;
    }
    else h=m-1;
    }
   if (h==0) return 0;
   else return -1;



}

int main(){

int idx = find_missing();
cout << idx;


}
