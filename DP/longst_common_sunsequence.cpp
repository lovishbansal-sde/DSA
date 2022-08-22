#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int solve(string s1, string s2, int n, int m)
{
    if (n == 0 or m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = solve(s1, s2, n - 1, m - 1) + 1;
    }
    return dp[n][m] = max(solve(s1, s2, n - 1, m), solve(s1, s2, n, m - 1));
}
int solvebottom(string s1,string s2,int n,int m)
{
    
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2, s1.length(), s2.length());
}