#include <iostream>
using namespace std;
int solve(int n,int*dp)
{
    if(n==0 || n==1 )
    return n;
    if(dp[n]!=0) return dp[n];
    int ans= (solve(n-1,dp)+solve(n-2,dp));
    dp[n]=ans;
    return ans;
}
int solveBottomUp(int n)
{
    int dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int solveSpaceOptimization(int n)
{
    int a=0,b=1,c=0;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int32_t main(){
    int n;
    cin>>n;
    int dp[1000]={0};
    cout<<solveSpaceOptimization(n);
}
