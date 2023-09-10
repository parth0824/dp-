#include <bits/stdc++.h>
using namespace std;
/*
// ------------------------------------- pure recursive code [TLE mare ga] -----------------------------
int findpath(int i, int j, int n, int m)
{
    if (i == n || j == m || i < 0 || j < 0)
        return 0;
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    int down = findpath(i, j + 1, n, m);
    int right = findpath(i + 1, j, n, m);
    return down + right;
}
int uniquePaths(int n, int m)
{
    return findpath(0, 0, n, m);
}
*/
// ------------------------------------- memoization -----------------------------
/*
int find_path(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n || j == m || i < 0 || j < 0)
        return 0;
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j] != 0)
        return dp[i][j];
    int down = find_path(i, j + 1, n, m, dp);
    int right = find_path(i + 1, j, n, m, dp);
    return dp[i][j] = down + right;
}
int uniquePaths(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return find_path(0, 0, n, m, dp);
}
*/
// ------------------------------------- tabulation -----------------------------
int uniquePaths(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            dp[i][j] += dp[i][j + 1];
            dp[i][j] += dp[i + 1][j];
        }
    }
    return dp[0][0];
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m);
}