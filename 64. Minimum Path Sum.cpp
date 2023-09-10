#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define ll long long int
#define pb push_back
#define vi vector<int>
void printvector(vvi &v)
{
    for (auto i : v)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
/*
// -------------------------------------- pure recursion[TLE mere ga] -----------
ll findans(int i, int j, vvi &v)
{
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (i == 0 && j == 0)
    {
        return v[0][0];
    }
    long long int up = v[i][j] + findans(i - 1, j, v);
    long long int left = v[i][j] + findans(i, j - 1, v);
    return min(up, left);
}
int minPathSum(vvi &v)
{
    return findans(v.size() - 1, v[0].size() - 1, v);
}
*/
/*
// -------------------------------------- memoization ---------------------------
ll findans(int i, int j, vvi &v, vvi &dp)
{
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0 && j == 0)
    {
        return v[0][0];
    }
    long long int up = v[i][j] + findans(i - 1, j, v, dp);
    long long int left = v[i][j] + findans(i, j - 1, v, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> &v)
{
    vector<vector<int>> dp(v.size(), vector<int>(v[0].size(), -1));
    return findans(v.size() - 1, v[0].size() - 1, v, dp);
}
*/
// -------------------------------------- tabulation ---------------------------
int minPathSum(vector<vector<int>> &v)
{
    vector<vector<int>> dp(v.size(), vector<int>(v[0].size(), 0));
    dp[0][0] = v[0][0];
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (!(i == 0 && j == 0))
            {
                long long int up = INT_MAX, left = INT_MAX;
                if (i - 1 >= 0)
                    up = v[i][j] + dp[i - 1][j];
                if (j - 1 >= 0)
                    left = v[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[v.size() - 1][v[0].size() - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    int x;
    vvi v;
    for (int i = 0; i < n; i++)
    {
        vi help;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            help.pb(x);
        }
        v.pb(help);
    }
    cout << minPathSum(v);
    return 0;
}