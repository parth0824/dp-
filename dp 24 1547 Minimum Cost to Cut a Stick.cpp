// given-a-rod-of-length-n-units-the-rod-can-be-cut-into-different-sizes-and-each-size-has-a-cost-associated-with-it-determine-the-maximum-cost-obtained-by-cutting-the-rod-and-selling-its-pieces
#include <bits/stdc++.h>
using namespace std;
/*
// --------------------------- recursive TLE :(---------------------------------------
int findans(int i, int k, vector<int> &v)
{
    if (i == 0)
    {
        return v[0] * k;
    }
    int take = INT_MIN;
    if (i < k)
    {
        take = findans(i, k - i - 1, v) + v[i];
    }
    int nottake = findans(i - 1, k, v);
    return max(take, nottake);
}
int cutsRod(vector<int> &v, int n)
{
    return findans(n - 1, n, v);
}
*/
/*
// --------------------------- memoization ---------------------------------------
int findans(int i, int k, vector<int> &v, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return v[0] * k;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    int take = INT_MIN;
    if (i < k)
    {
        take = findans(i, k - i - 1, v, dp) + v[i];
    }
    int nottake = findans(i - 1, k, v, dp);
    return dp[i][k] = max(take, nottake);
}
int cutRod(vector<int> &v, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return findans(n - 1, n, v, dp);
}
*/
/*
// --------------------------- tabulation ---------------------------------------
int cutRod(vector<int> &v, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = v[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k < n + 1; k++)
        {
            int take = 0;
            if (i < k)
            {
                take = dp[i][k - i - 1] + v[i];
            }
            int nottake = dp[i - 1][k];
            dp[i][k] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
}
*/
// --------------------------- space optimized the best ---------------------------------------
int cutRod(vector<int> &v, int n)
{
    vector<int> cur(n + 1, 0);
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        pre[i] = v[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k < n + 1; k++)
        {
            int take = 0;
            if (i < k)
            {
                take = cur[k - i - 1] + v[i];
            }
            int nottake = pre[k];
            cur[k] = max(take, nottake);
        }
        pre = cur;
    }
    return pre[n];
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << cutRod(v, n) << endl;
    return 0;
}