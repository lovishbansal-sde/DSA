// Longest Common Substring
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    int n=s1.length();
    int m=s2.length();
    int ans=0,row=0,col=0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = 0;
            if(dp[i][j]>ans)
            {
                row=i;
                col=j;
            }
            ans=max(ans,dp[i][j]);
        }
    }
        for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<ans;
while(dp[row][col]!=0)
{
    cout<<s1[row-1];
    row--;
    col--;
}
}