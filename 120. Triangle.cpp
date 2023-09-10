#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define ll long long int
#define pb push_back
#define vi vector<int>
/*
// ----------------------------------------- pure recursive code[TLE mare ga] --------------------------------
int findans(int i, int j, vvi &v)
{
    if (j < 0 || j > v[i].size() - 1 || i < 0 || i > v.size() - 1)
    {
        return 0;
    }
    if (i == v.size() - 1)
    {
        return v[i][j];
    }
    int l = v[i][j] + findans(i + 1, j, v);
    int r = v[i][j] + findans(i + 1, j + 1, v);
    return min(l, r);
}
int minimumTotal(vvi &v)
{
    return findans(0, 0, v);
}
*/

/*

// ----------------------------------------- memoization --------------------------------
int findans(int i, int j, vvi &v, vvi &dp)
{
    if (j < 0 || j > v[i].size() - 1 || i < 0 || i > v.size() - 1)
    {
        return 0;
    }
    if (i == v.size() - 1)
    {
        return v[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int l = v[i][j] + findans(i + 1, j, v, dp);
    int r = v[i][j] + findans(i + 1, j + 1, v, dp);
    return dp[i][j] = min(l, r);
}
int minimumTotal(vvi &v)
{
    vvi dp(v.size(), vi(v[v.size() - 1].size(), -1));
    return findans(0, 0, v, dp);
}
*/



// ----------------------------------------- tabulation --------------------------------
int minimumTotal(vector<vector<int>> &v)
{

    vvi dp(v.size(), vi(v[v.size() - 1].size(), 0));

    dp[v.size() - 1] = v[v.size() - 1];

    for (int i = v.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            int l = v[i][j] + dp[i + 1][j];
            int r = v[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(l, r);
        }
    }

    return dp[0][0];
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
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            help.pb(x);
        }
        v.pb(help);
    }
    cout << minimumTotal(v);
    return 0;
}
