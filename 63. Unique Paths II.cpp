#include <bits/stdc++.h>
using namespace std;
/*
// ------------------------------ memoization ------------------------------------
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    return uniquePaths(obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid);
}
int find_path(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &v)
{
    if (i == n || j == m || i < 0 || j < 0)
    {
        return 0;
    }
    if (v[i][j] == 1)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    int down = find_path(i, j + 1, n, m, dp, v);
    int right = find_path(i + 1, j, n, m, dp, v);
    return dp[i][j] = down + right;
}
int uniquePaths(int n, int m, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return find_path(0, 0, n, m, dp, v);
}
*/
// ------------------------------ tabulation ------------------------------------
int uniquePaths(int n, int m, vector<vector<int>> &v)
{
    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, 0));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 1)
                dp[i][j] = -1;
        }
    }
    if (dp[n - 1][m - 1] == -1 || dp[0][0] == -1)
        return 0;
    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (dp[i][j] != -1)
            {
                if (dp[i][j + 1] != -1)
                {
                    dp[i][j] += dp[i][j + 1];
                }
                if (dp[i + 1][j] != -1)
                {
                    dp[i][j] += dp[i + 1][j];
                }
            }
        }
    }
    return dp[0][0];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    return uniquePaths(obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        vector<int> help;
        int x;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            help.push_back(x);
        }
        v[i] = help;
    }
    cout << uniquePathsWithObstacles(v);
}