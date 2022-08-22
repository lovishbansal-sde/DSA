                                // DOUBT
#include<iostream>
using namespace std;
int solve(int *arr,int i,int j,int ans)
{
    if(i>j) 
        return 0;

    int c=0;
    int a=arr[i] + solve(arr,i+1,j,ans);
    int b=arr[j]+solve(arr,i,j-1,ans);
    if(i+1<=j-1)
        c=solve(arr,i+1,j-1,ans);

    if(max(a,max(b,c))>ans)
    ans=max(a,max(b,c));
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int  i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,0,n-1,0);
}