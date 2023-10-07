#include <bits/stdc++.h>
using namespace std;
string findlca(string &a, string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i < a.size() + 1; i++)
    {
        for (int j = 1; j < b.size() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    int c = 0;
    string s = "";
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            s += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] < dp[i - 1][j])
        {
            i--;
        }
        else
            j--;
    }
    reverse(s.begin(), s.end());
    return s;
}
string shortestCommonSupersequence(string a, string b)
{
    // find the lca string
    string lcs = findlca(a, b);
    int i = 0, j = 0;
    int k = 0;
    string ans = "";
    while (i < a.size() && j < b.size())
    {
        if (a[i] == lcs[k] && b[j] == lcs[k])
        {
            ans += lcs[k++];
            i++;
            j++;
        }
        else
        {
            if (a[i] != lcs[k])
                ans += a[i++];
            if (b[j] != lcs[k])
                ans += b[j++];
        }
    }
    while (i < a.size())
        ans += a[i++];
    while (j < b.size())
        ans += b[j++];
    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortestCommonSupersequence(s1, s2);
    return 0;
}