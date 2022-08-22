#include <bits/stdc++.h>
using namespace std;
//#define OJ freopen("E:/DS ALGO/Programing Question/input.txt", "r",stdin);  freopen("E:/DS ALGO/Programing Question/output.txt", "w",stdout);
#define int long long
int solve(int*arr,int n,int k){
    int pre=0,ans=0;
    map<int,int> mp;
    //Sum Index
    for(int i=0;i<n;i++){
        pre=pre+arr[i];
        if(pre==k)
        ans=max(ans,i+1);
        if(mp.count(pre-k))
        ans=max(ans,i-mp[pre-k]);
        else mp[pre]=i;
    }
    return ans;
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
