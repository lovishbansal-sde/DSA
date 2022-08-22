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

int solve(int n)
{
    int start = 0,ans=0;
    int end=n;
    while(start <= end)
    {
        int mid=(start+end)/2;
        if(mid*mid==n)
        return mid;
        else if(mid*mid<n){
        start=mid+1;
        ans=mid;
        }
        else end=mid-1;
    }
    return ans;

}
int32_t main(){
//OJ;
//fast
int n;
cin>>n;
int ans=solve(n);
    float ans2=ans;
        float inc=0.1;
    for(int times=1;times<=5;times++)
    {
        while(ans2*ans2<=n)
        {
            // cout<<"Hi";
            ans2=ans2+inc;
        }
        // overshot the value
        ans2=ans2-inc;
        inc=inc/10;
    }
    cout<<ans2;

}
