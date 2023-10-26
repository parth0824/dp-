// Given two strings s and t, return the number of distinct subsequences of s which equals t.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// int findans(int i, int j, string &a, string &b, vector<vector<int>> &dp){
//     if (j == 0)return 1;
//     else if (i == 0)return 0;
//     else if (dp[i][j] != -1)return dp[i][j];
//     if (a[i-1] == b[j-1])return dp[i][j] = findans(i - 1, j - 1, a, b, dp) + findans(i - 1, j, a, b, dp);
//     return dp[i][j] = findans(i - 1, j, a, b, dp);
// }
// int numDistinct(string &a, string &b){
//     vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, -1));
//     return findans(a.size() , b.size() , a, b, dp);
// }
// int findans(int i, int j, string &a, string &b, vector<vector<int>> &dp){
//     if (j == 0)return 1;
//     else if (i == 0)return 0;
//     else if (dp[i][j] != -1)return dp[i][j];
//     if (a[i-1] == b[j-1])return dp[i][j] = findans(i - 1, j - 1, a, b, dp) + findans(i - 1, j, a, b, dp);
//     return dp[i][j] = findans(i - 1, j, a, b, dp);
// }
int numDistinct(string &a, string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 0; i < a.size(); i++)
        dp[i][0] = 1;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[a.size()][b.size()];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << numDistinct(s1, s2);
    return 0;
}