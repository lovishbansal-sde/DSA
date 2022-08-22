#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int *arr,int n,int k)
{
    int pre=0,cnt=0;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        pre=pre+arr[i];
        if(pre-k==0)
        cnt++;
        if(mp.count(pre-k))
        cnt+=mp[pre-k];
        mp[pre]++;
    }
    return cnt;
}
int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<solve(arr,n,k);    
}
