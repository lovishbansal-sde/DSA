#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int *prices, int *weights, int i, int n, int c, int dp[][100])
{
    if (i == n || c == 0)
    {
        dp[i][c] = 0;
        return 0;
    }
    if (dp[i][c] != -1)
        return dp[i][c];
    int a = 0, b = 0;
    if (weights[i] <= c)
        a = solve(prices, weights, i + 1, n, c - weights[i], dp) + prices[i];
    b = solve(prices, weights, i + 1, n, c, dp);
    return dp[i][c] = max(a, b);
}

int32_t main()
{
    int i = 0, c = 50;
    int n = 3;
    int prices[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    cout << solve(prices, weights, i, n, c, dp);
}
