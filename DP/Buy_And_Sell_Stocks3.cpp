#include<iostream>
#include<climits>
using namespace std;
int maxi(int *arr,int n,int a,int b)
{
    int ans=INT_MIN;
    for(int i=a;i<=b;i++)
    {
        if(arr[i]>ans) ans=arr[i];
    }
    return ans;
}
int mini(int *arr,int n,int a,int b)
{
    int ans=INT_MAX;
    for(int i=a;i<=b;i++)
    {
        if(arr[i]<ans) ans=arr[i];
    }
    return ans;
}
int solve(int *arr,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,n);
}