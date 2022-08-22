#include<iostream>
using namespace std;
#define int long long
int solve(int*arr,int n)
{
    int left[n];
    int right[n];
    left[0]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            left[i]=max(left[j]+1,left[i]);
        }
        // Lovish op 
        // thei 
    }
    right[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        right[i]=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            right[i]=max(right[i],right[j]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) 
    {
        ans=max(ans,left[i]+right[i]-1);
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,n);
}
