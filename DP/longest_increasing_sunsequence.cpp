#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int*arr,int n)
{
    int out[n];
    for(int i = 0; i < n; i++)
    out[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            out[i]=max(out[i],out[j]+1);
        }
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        // cout<<out[i]<<" ";
        m=max(m,out[i]);
    }
    return m;
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,n);
}