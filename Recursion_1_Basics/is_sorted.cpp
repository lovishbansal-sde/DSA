#include <bits/stdc++.h>
using namespace std;
// #define OJ freopen("E:/DS ALGO/Programing Question/input.txt", "r",stdin);  freopen("E:/DS ALGO/Programing Question/output.txt", "w",stdout);
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool solve(int*arr,int n)
{
    if(n==0 or n==1)
    return true;
    bool check=solve(arr+1,n-1);
    if(arr[0]<arr[1] and check) return true;
    else return false;
}
int32_t main(){
//OJ;
//fast
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
}
