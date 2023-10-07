// keep the palindromic subsequence portion intact in the original string and subtract it from the original string length
#include <bits/stdc++.h>
using namespace std;
int lcs(string s, string sr)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(sr.size() + 1, 0));
    int ans = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= sr.size(); j++)
        {
            if (s[i - 1] == sr[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
int longestPalindromeSubseq(string s)
{
    string sr = s;
    reverse(s.begin(), s.end());
    return lcs(s, sr);
}
int minInsertions(string s)
{
    return s.size() - longestPalindromeSubseq(s);
}
int main()
{
    string s;
    cin >> s;
    cout << minInsertions(s);
    return 0;
}