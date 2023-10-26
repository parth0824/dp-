// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Constraints->
// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.
#include <bits/stdc++.h>
using namespace std;
bool findans(int i, int j, string &a, string &b, vector<vector<int>> &dp)
{
    if (i == -1 && j == -1)
        return 1;
    if (j < 0)
        return 0;
    if (i < 0)
    {
        for (int e = 0; e <= j; e++)
        {
            if (b[e] != '*')
                return 0;
        }
        return 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j] || b[j] == '?')
    {
        return dp[i][j] = findans(i - 1, j - 1, a, b, dp);
    }
    else if (b[j] == '*')
    {
        return dp[i][j] = findans(i - 1, j, a, b, dp) || findans(i, j - 1, a, b, dp);
    }
    else
    {
        return dp[i][j] = 0;
    }
}
bool isMatch(string a, string b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    return findans(a.size() - 1, b.size() - 1, a, b, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << isMatch(s1, s2);
    return 0;
}