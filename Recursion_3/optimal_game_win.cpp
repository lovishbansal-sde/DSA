#include <bits/stdc++.h>
using namespace std;
//#define OJ freopen("E:/DS ALGO/Programing Question/input.txt", "r",stdin);  freopen("E:/DS ALGO/Programing Question/output.txt", "w",stdout);
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int solve(int*arr,int i,int j)
{
    if(i+1==j)
    return max(arr[i],arr[j]);
    // First Pick 
    int a=min(solve(arr,i+1,j-1),solve(arr,i+2,j))+arr[i];
    int b=min(solve(arr,i,j-2),solve(arr,i+1,j-1))+arr[j];
    return max(a,b);
}
int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,0,n-1);
}
