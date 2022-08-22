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

bool solve(int* arr,int n,int cows,int min_distance)
{
    int last_cow=arr[0];
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-last_cow>=min_distance)
        {
            ans++;
            last_cow=arr[i];
        }
        if(ans==cows)
        return true;
    }
    return false;
}

int32_t main(){
//OJ;
//fast
    int stalls[]={1,2,4,8,9};
    int n=5;
    int cows=3;
    int ans=-1;
    int start=0,end=stalls[n-1]-stalls[0];
    while(start<=end){
        int mid=(start+end)/2;
        bool sol=solve(stalls,n,cows,mid);
        if(sol)
        {
            ans=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    cout<<ans;
}
