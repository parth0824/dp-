// Given two strings s1 and s2, return the minimum number of operations required to convert s1 to s2.
#include <bits/stdc++.h>
using namespace std;
// int findans(int i, int j, string &a, string &b,vector<vector<int>> &dp){
//     if (i == 0)return j;
//     else if (j == 0)return i;
//     if(dp[i][j] != -1) return dp[i][j];
//     if (a[i-1] == b[j-1])return dp[i][j] = findans(i - 1, j - 1, a, b,dp);
//     return dp[i][j] = min(findans(i - 1, j, a, b,dp), min(findans(i, j - 1, a, b,dp), findans(i - 1, j - 1, a, b,dp))) + 1;
//     //                    delete                            insert                   replace
// }
// int minDistance(string a, string b){
//     vector<vector<int>> dp(a.size()+1,vector<int> (b.size()+1,-1));
//     return findans(a.size() , b.size() , a, b,dp);
// }
int minDistance(string a, string b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 0; i <= a.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= b.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    } 
    return dp[a.size()][b.size()];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2);
    return 0;
}