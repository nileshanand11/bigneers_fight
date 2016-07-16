#include <bits/stdc++.h>

using namespace std;

int ar[]={8,4,5,2,12};
stack<int>s;
int main(){
s.push(ar[0]);
int i=0,l=sizeof(ar)/sizeof(ar[0]);
while(++i<l){
while(ar[i]>s.top()){
    printf("%d -> %d\n",s.top(),ar[i]);
    if(s.empty()) break;
    s.pop();
    }
if(s.empty())  s.push(ar[i]);
else if(ar[i]<=s.top())  s.push(ar[i]);
}
while(!s.empty()){
    printf("%d -> -1\n",s.top());
    s.pop();
    }
}
