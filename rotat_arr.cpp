//search rotated sorted array
#include <cstdio>
#include <iostream>

using namespace std;
int arr[]={4,5,6,7,2,3};
int length =6;
int key=0;
void display ( int len){
for(int i=0;i<len;i++)
    cout<<arr[i];
    cout<<endl;
}
int pivot(int len){
int low,high,mid;
low =0;
high=len-1;
//cout << endl;
while (low<=high){
mid=(low+high)/2;
//cout << "mid "<< mid<< endl;
if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])    return mid;
else if( arr[mid]>arr[low] && arr[mid]>arr[high]) low=mid+1;
else high = mid-1;
}
}
bool isKey( int p, int k){
int l=0,h=length-1;
if(k>=arr[l] ) h=p;
else  l=p+1;
int mid;
while (l<=h){
    mid =(l+h)/2;
    if(k==arr[mid]) return true;
    if (k<arr[mid]) h=mid-1;
    else l=mid+1;
    }

    return false;
}


int main(){
display (length);
int p = pivot (length);
bool val =isKey(p , key);
if (val) cout << "true" ;
else cout << "false";


}
