// max in k sub array
#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;

int arr[]={12, 1, 78, 90, 57, 89, 56};
int len=sizeof(arr)/sizeof(arr[0]);
int k=2;
void printKMax(){
deque <int> Q;
int i;
for (i=0;i<k;i++){

    while (!Q.empty()&&arr[i]>=arr[Q.back()])
        Q.pop_back();
    Q.push_back(i);
}
//processing rest of elements
for(i=k;i<len;i++){
        cout << arr[Q.front()]<<" ";
    while (!Q.empty() && Q.front() <=i-k)
            Q.pop_front();
    while(!Q.empty() && arr[i]>=arr[Q.back()])
        Q.pop_back();
    Q.push_back(i);
    }
    cout<< arr[Q.front()]<< " ";
}



int main(){
printKMax();

return 0;
}
