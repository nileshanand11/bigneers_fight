//http://www.geeksforgeeks.org/shortest-common-supersequence/
///shortest common super sequence
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
//int i=0;
/*int scs_recr(char *s1, char *s2, int m , int n){
if(m==0) return n;
if(n==0) return m;
cout<<++i<<" ";
if(s1[m-1]==s2[n-1]) {  //cout <<"IF ";
 return (1+scs_recr(s1,s2,m-1,n-1));}
else return (1+ (scs_recr(s1,s2,m,n-1)<scs_recr(s1,s2,m-1,n))?scs_recr(s1,s2,m,n-1):scs_recr(s1,s2,m-1,n));
}*/

string  scs_dp( char *s1, char *s2){
int m=strlen(s1),n=strlen(s2),i,j;
int dp[m+1][n+1];
string s;
for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else                      dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int idx=dp[m][n];
    cout<<idx<<endl;
    i=m,j=n;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]) {s.push_back(s1[i-1]); j--;i--;}
        else if(dp[i-1][j] > dp[i][j-1]){ s.push_back(s2[j-1]);j--;}
        else {s.push_back(s1[i-1]);i--;}
    }
            while (i > 0) {s.push_back(s1[i-1]);--i;}
        while (j > 0) { s.push_back(s2[j-1]);--j;}
    cout<<s<<endl;
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int val=0;
char arr1[]="geek";
char arr2[]="eke";

//int sc=scs_recr(arr1,arr2,4,3);

cout<< scs_dp(arr1,arr2);

}
