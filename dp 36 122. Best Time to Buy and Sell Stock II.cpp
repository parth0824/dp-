#include <bits/stdc++.h>
using namespace std;
int maxProfit1(vector<int> &v)
{
    int ans = 0;
    int pre = v[0];
    for (auto i : v)
    {
        if (pre < i)
        {
            ans += (i - pre);
        }
        pre = i;
    }
    return ans;
}
int findans(int i, bool chk, vector<int> &v, vector<vector<int>> &dp)
{
    if (i == v.size())
        return 0;
    if (dp[i][chk] != -1)
        return dp[i][chk];
    if (chk)
        return dp[i][chk] = max(findans(i + 1, 0, v, dp) - v[i], findans(i + 1, 1, v, dp));
    else
        return dp[i][chk] = max(v[i] + findans(i + 1, 1, v, dp), findans(i + 1, 0, v, dp));
}
int maxProfit(vector<int> &v)
{
    vector<vector<int>> dp(v.size(), vector<int>(2, -1));
    return findans(0, 1, v, dp);
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << maxProfit(v);
    return 0;
}