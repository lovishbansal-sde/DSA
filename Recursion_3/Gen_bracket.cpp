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

void solve(int n, char* output,int i,int open,int close) 
{
    if(i==2*n)
    {
        output[i] = '\0';
        cout<<output<<"     ";
        return;
    }
    if(open<n)
    {
        output[i]='{';
        solve(n,output,i+1,open+1,close);
    }
    if(close<open)
    {
        output[i]='}';
        solve(n,output,i+1,open,close+1);
    }

}
int32_t main(){
    int n=3;
    char output[10];
    int i=0,open=0,close=0;
    solve(n,output,i,open,close);
}
