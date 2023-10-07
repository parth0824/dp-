#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i] == b[j])
        {
            return 1 + lcs(i - 1, j - 1, a, b, dp);
        }
        int l = lcs(i - 1, j, a, b, dp);
        int r = lcs(i, j - 1, a, b, dp);
        return dp[i][j] = max(l, r);
    }
    int minDistance(string a, string b)
    {
        if (a.size() == 1 && b.size() == 1)
        {
            if ((a[0] == b[0]))
                return 0;
            return 2;
        }
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
        return a.size() + b.size() - (2 * lcs(a.size() - 1, b.size() - 1, a, b, dp));
    }
};





int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i] == b[j])
    {
        return 1 + lcs(i - 1, j - 1, a, b, dp);
    }
    int l = lcs(i - 1, j, a, b, dp);
    int r = lcs(i, j - 1, a, b, dp);
    return dp[i][j] = max(l, r);
}
int minDistance(string a, string b)
{
    if (a.size() == 1 && b.size() == 1)
    {
        if ((a[0] == b[0]))
            return 0;
        return 2;
    }
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
    return a.size() + b.size() - (2 * lcs(a.size() - 1, b.size() - 1, a, b, dp));
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2);
}