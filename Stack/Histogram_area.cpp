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

void solve_nsl(int*input,int n,int* nsl)
{
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        if(s.empty()==true)
        {
            nsl[i]=-1;
        }
        if(s.empty()==false)
        {
            while(s.empty()==false and s.top().first >=input[i])
            {
                s.pop();
            }
        }
        if(s.empty()==true)
        {
            nsl[i]=-1;
        }
        else nsl[i]=s.top().second;
        s.push(make_pair(input[i],i));
    }
}
void solve_nsr(int*input,int n,int* nsr)
{
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()==true)
        {
            nsr[i]=n+1;
        }
        if(s.empty()==false)
        {
            while(s.empty()==false and s.top().first >=input[i])
            {
                s.pop();
            }
        }
        if(s.empty()==true)
        {
            nsr[i]=n;
        }
        else nsr[i]=s.top().second;
        s.push(make_pair(input[i],i));
    }
}
int32_t main(){
    int n;
    cin>>n;
    int input[n],nsr[n],nsl[n];
    for(int i=0;i<n;i++)
    cin>>input[i];
    solve_nsl(input,n,nsl);
    solve_nsr(input,n,nsr);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        // cout<<nsr[i]<<" ";
        ans=max(ans,abs(nsr[i]-nsl[i]-1)*input[i]);
    }
    cout<<ans;
}
