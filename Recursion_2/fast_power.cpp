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

int power(int n,int m)
{
    if(m==0) return 1;
    if(m==1) return n;
    // odd
    int a=power(n,m/2);
    if(m&1) return n*a*a;
    else return a*a;
}
int32_t main(){
    int n;
    cout<<power(9,10);
}
