// brute force is exponential TLE
#include <bits/stdc++.h>
using namespace std;

// ---------------------------- recursive tle ------------------------------
int findans(string &a, string &b, int i, int j)
{
    if (i < 0 || j < 0)
    {
        
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + findans(a, b, i - 1, j - 1);
    }
    else
    {
        return max(findans(a, b, i - 1, j), findans(a, b, i, j - 1));
    }
}
int longestCommonSubsequence(string a, string b)
{
    return findans(a, b, a.size() - 1, b.size() - 1);
}

/*
// ---------------------------- memoization ------------------------------
int findans(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (dp[i - 1][j - 1] != -1)
    {
        return dp[i - 1][j - 1];
    }
    if (a[i - 1] == b[j - 1])
    {
        return dp[i][j]= 1 + findans(a, b, i - 1, j - 1, dp);
    }
    else
    {
        return dp[i][j] = max(findans(a, b, i - 1, j, dp), findans(a, b, i, j - 1, dp));
    }
}
int longestCommonSubsequence(string a, string b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    return findans(a, b, a.size(), b.size(), dp);
}
*/
int longestCommosnSubsequence(string a, string b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0)); // dp[a.size()-1][b.size()-1]
    for (int i = 0; i < b.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // findans(a, b, i - 1, j - 1, dp);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // findans(a, b, i - 1, j, dp), findans(a, b, i, j - 1, dp));
            }
        }
    }
    // actual subsequence answer
    int m = 0;
    string s = "";
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (m < dp[i][j])
            {
                s += a[i - 1];
                m = dp[i][j];
            }
        }
    }
    cout << s << endl;
    return dp[a.size()][b.size()];
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b);
    return 0;
}