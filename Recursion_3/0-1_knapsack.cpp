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

int solve(int* prices,int* weights,int i,int n,int c)
{
    if(i==4)
    { 
        return 0;
    }
    int a=0,b=0;
    if(weights[i]<c)
    a=solve(prices,weights,i+1,n,c-weights[i])+prices[i];
    b=solve(prices,weights,i+1,n,c);
    return max(a,b);
}
int32_t main(){
    int i=0,ans=0,c=7;
    int n=4;
    int prices[]={40,20,35,100};
    int weights[]={1,2,3,5};
    cout<<solve(prices,weights,i,n,c);
}
