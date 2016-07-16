// print index for sorted array.
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int arr[]={1,2,3,3,6,6,7,7,8};
int len = sizeof(arr)/sizeof(arr[0]);
int key=3;
void print_arr(){
for (int i=0;i<len;i++)
    cout<< arr[i]<<" ";
cout << endl;
}
int print_L_indx(int k){
int l = 0,h = len -1;
int m=-1;

if (arr[l]==k) return 0;

while (l<=h){
        m=(l+h)/2;
        if(arr[m]==k&&arr[m-1]!=k){
                return m;
            }
        else if (arr[m]<k) l=m+1;
        else h=m-1;
    }
    return -1;
}
int print_H_indx(int k){
int l = 0,h = len -1;
int m=-1;
if (arr[h]==k) return h;
while (l<=h){
        m=(l+h)/2;
       // cout<< "m " << m<<endl;
        if(arr[m]==k&&arr[m+1]!=k){
                return m;
            }
        else if (arr[m]>k) h=m-1;
        else l=m+1;
    }
    return -1;
}


int main(){
int lix,hix;
print_arr();
cin>>key;
lix = print_L_indx(key);
cout<< lix;
hix = print_H_indx(key);
cout<<  endl;
cout<< hix;
return 0;
}
