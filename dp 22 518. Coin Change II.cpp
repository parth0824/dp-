#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int u=0;
int findans(int i, int k, vector<int> &v, vector<vector<int>> &dp)
{ 
    if (i == 0)
    {
        return k%v[0]==0;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    int take = 0;
    if (v[i] <= k)
    {
        take = findans(i, k - v[i], v, dp) ;
    }
    int nottake = findans(i - 1, k, v, dp);
    return dp[i][k] = take + nottake;
}
int change(int k, vector<int> &v)
{
    if (k == 0)
        return 0;
    if (v.size() == 1)
    {
        return (k % v[0] == 0) ? 1 : 0;
    }
    vector<vector<int>> dp(v.size(), vector<int>(k + 1, -1));
    int ans = findans(v.size() - 1, k, v, dp);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    int k;
    cin >> k;
    cout << change(k, v);
}


