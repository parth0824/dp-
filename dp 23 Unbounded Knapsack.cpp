// p
// w
#include <bits/stdc++.h>
using namespace std;
/*
// ----------------------------- recursive -> TLE :(
int findans(int i, int k, vector<int> &p, vector<int> &w)
{
    if (k <= 0)
    {
        return 0;
    }
    if (i == 0)
    {
        int n = k / w[0];
        return p[0] * n;
    }
    int take = 0;
    if (k >= w[i])
    {
        take = findans(i, k - w[i], p, w) + p[i];
    }
    int nottake = findans(i - 1, k, p, w);
    return max(take, nottake);
}
*/
/*
// ----------------------------- tabulation
int findans(int i, int k, vector<int> &p, vector<int> &w, vector<vector<int>> &dp){
    if (k <= 0) return 0;
    if (i == 0) return p[0] * (k / w[0]);
    if (dp[i][k] != -1) return dp[i][k];
    int take = 0;
    if (k >= w[i]) take = findans(i, k - w[i], p, w, dp) + p[i];
    int nottake = findans(i - 1, k, p, w, dp);
    return dp[i][k] = max(take, nottake);
}
int unboundedKnapsack(int n, int k, vector<int> &p, vector<int> &w){
    // greedy will not work here
    vector<vector<int>> dp(n,vector<int>(10001, -1));
    return findans(n - 1, k, p, w, dp);
}
*/
// ----------------------------- memoization --------------------------------------
int findans(int n, int k, vector<int> &p, vector<int> &w)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0)); 
    for (int i = 0; i <= k; i++)
        dp[0][i] = ((p[0]) * (i / w[0]));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int take = 0;
            if (j >= w[i])
                take = dp[i][j - w[i]] + p[i];
            int nottake = dp[i - 1][j];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][k];
}

int unboundedKnapsack(int n, int k, vector<int> &p, vector<int> &w)
{
    // greedy will not work here
    return findans(n - 1, k, p, w);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n, -1);
    vector<int> w(n, -1);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        p[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        w[i] = x;
    }
    cout << unboundedKnapsack(n, k, p, w);
    return 0;
}
