#include <bits/stdc++.h>
using namespace std;
/*
// --------------recursive -------------------------------
int findans(int i, int j, string &a, string &b, int ans)
{
    if (i < 0 || j < 0)
    {
        return ans;
    }
    if (a[i] == b[j])
    {
        ans = findans(i - 1, j - 1, a, b, ans + 1);
    }
    int x = findans(i - 1, j, a, b, 0);
    int y = findans(i, j - 1, a, b, 0);
    return max(ans, max(x, y));
}
int lcs(string &a, string &b)
{
    int ans = 0;
    return findans(a.size() - 1, b.size() - 1, a, b, ans);
}
*/
// -- -- -- -- -- -- -- -- -- --tabulation
int lcs(string &a, string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    int ans = 0;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int length = lcs(s1, s2);
    cout << length << endl;

    return 0;
}