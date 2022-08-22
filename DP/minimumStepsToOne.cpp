#include <iostream>
using namespace std;
int solve(int n,int*dp)
{

    if(n==0 || n==1) return 0;
    if(dp[n]!=0) return dp[n];
    int a=10000,b=10000,c=10000;
    if(n%3==0)
    a=solve(n/3,dp);
    if(n%2==0)
    b=solve(n/2,dp);
    c=solve(n-1,dp);
    dp[n]= min(a,min(b,c))+1;
    return dp[n];
}
int solveBottomUp(int n)
{
    int dp[n];
    dp[0]=dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int a=10000,b=10000,c=10000;
        if(i%2==0)
        a=dp[i/2];
        if(i%3==0)
        b=dp[i/3];
        c=dp[i-1];
        dp[i]=dp[n]= min(a,min(b,c))+1;
    }
    return dp[n];

}
int32_t main(){
    int n;
    cin>>n;
    int dp[1000]={0};
    cout<<solveBottomUp(n);
}
