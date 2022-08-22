#include<iostream>
using namespace std;
int solve(int money,int* coins,int coinSize,int*dp)
{
    if(money <= 0 )
    return 0;
    if(dp[money] != 0)
    return dp[money];
    int ans=1e9;
    for(int i=0;i<coinSize;i++)
    {
        if(money-coins[i]>=0)
        {
            int sub=solve(money-coins[i],coins,coinSize,dp);
            ans=min(ans,sub+1);
        }
    }
    // cout<<"HI";
    dp[money] =ans;
    return dp[money];
}
int solveBottomUp(int money,int* coins,int coinSize)
{
    int dp[money]={0};
    for(int i=1;i<=money;i++)
    {
        int ans=1e9;
        for(int j=0;j<coinSize;j++)
        {
            if(i-coins[j]>=0)
            ans=min(ans,dp[i-coins[j]]+1);
        }
        dp[i]=ans;
    }
    return dp[money];
}
int main()
{
    int money;
    cout<<"Enter Money ";
    cin>>money;   
    // int dp[1000]={0};
    int coins[]={1,2,5,10,20,50,100,500,2000};
    cout<<solveBottomUp(money,coins,9);
}