#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long int
#define pb push_back
using namespace std;

/*
// ----------------------------------- recursive [tle] ------------------------------------
ll findans(int i, int j, vvi &v)
{
    if (i < 0 || j < 0 || i >= v.size() || j >= v.size())
    {
        return INT_MAX;
    }
    if (i == v.size() - 1)
    {
        return v[i][j];
    }
    ll down = v[i][j] + findans(i + 1, j, v);
    ll downright = v[i][j] + findans(i + 1, j + 1, v);
    ll downleft = v[i][j] + findans(i + 1, j - 1, v);
    return min(down, min(downleft, downright));
}x
int minFallingPathSum(vector<vector<int>> &v)
{
    ll num = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        num = min(num, findans(0, i, v));
    }
    return num;
}
*/
/*

// ----------------------------------- memoization [tle] ------------------------------------
ll findans(int i, int j, vvi &v, vvi &dp)
{
    if (i < 0 || j < 0 || i >= v.size() || j >= v.size())
    {
        return INT_MAX;
    }
    if (i == v.size() - 1)
    {
        return v[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll down = v[i][j] + findans(i + 1, j, v, dp);
    ll downright = v[i][j] + findans(i + 1, j + 1, v, dp);
    ll downleft = v[i][j] + findans(i + 1, j - 1, v, dp);
    return dp[i][j] = min(down, min(downleft, downright));
}
int minFallingPathSum(vector<vector<int>> &v)
{
    ll num = INT_MAX;
    vvi dp(v.size(), vi(v.size(), -1));
    for (int i = 0; i < v.size(); i++)
    {
        num = min(num, findans(0, i, v, dp));
    }
    return num;
}
*/
// ----------------------------------- tabulation ------------------------------------
int minFallingPathSum(vector<vector<int>> &v)
{
    vector<vector<long long int>> dp(v.size(), vector<long long int>(v.size(), -1));
    for (int i = 0; i < v.size(); i++)
    {
        dp[0][i] = v[0][i];
    }
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            ll down = 1e9, downright = 1e9, downleft = 1e9;
            if (i - 1 >= 0)
                down = v[i][j] + dp[i - 1][j];
            if (i - 1 >= 0 && j - 1 >= 0)
                downright = v[i][j] + dp[i - 1][j - 1];
            if (i - 1 >= 0 && j + 1 <= v.size() - 1)
                downleft = v[i][j] + dp[i - 1][j + 1];
            dp[i][j] = min(down, min(downleft, downright));
        }
    }
    ll ans = INT_MAX;
    for (auto i : dp[v.size() - 1])
    {
        ans = min(ans, i);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vvi v;
    int x;
    for (int i = 0; i < n; i++)
    {
        vi help;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            help.pb(x);
        }
        v.pb(help);
    }
    cout << minFallingPathSum(v) << endl;
    return 0;
}