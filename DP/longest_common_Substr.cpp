
// Longest Common Substring
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int res = 0;
int solve(string &s1, string &s2, int n, int m)
{

    if (n == 0 or m == 0)
        return 0;

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int ans = 0;
    if (s1[n - 1] == s2[m - 1])
    {
        ans = max(ans, 1 + solve(s1, s2, n - 1, m - 1));
    }
    dp[n][m] = ans;
    solve(s1, s2, n - 1, m);
    solve(s1, s2, n, m - 1);
    return dp[n][m];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2, s1.length(), s2.length());
    int ans = -1e9;
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            cout << dp[i][j] << "\n";
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

// class Solution {
// public:
//     int solve(vector<int> &s1, vector<int> &s2,int n,int m,int ans,vector<vector<int>> &dp){

//     if (n == 0 or m == 0)
//         return ans;
//     if (dp[n][m] != -1)
//         return dp[n][m];
//     if (s1[n - 1] == s2[m - 1])
//     {
//         ans = solve(s1, s2, n - 1, m - 1,ans+1,dp) ;
//     }
//     return  max(ans,  max(solve(s1, s2, n - 1, m,0,dp), solve(s1, s2, n, m - 1,0,dp)));
// }
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         // memset(dp,-1,sizeof(dp));
//         vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
//         return solve(nums1,nums2,nums1.size(),nums2.size(),0,dp);
//     }
// };