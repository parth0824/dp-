#include <bits/stdc++.h>
using namespace std;
// ----------------------------------  1  ---------------------------------------------
class Solution1_pure_recursion
{ // tc -> (2^n) sc -> o(n) {stack space}
public:
    int findans(vector<int> &v, int n)
    {
        if (n == 0)
        {
            return v[0];
        }
        if (n < 0)
            return 0;
        int left = v[n] + findans(v, n - 2);
        int right = findans(v, n - 1);
        return max(left, right);
    }
    int rob(vector<int> &v)
    {
        int ans = findans(v, v.size() - 1);
        return ans;
    }
};
// ----------------------------------  2  ---------------------------------------------
class Solution2_memoization
{ // tc -> (n) sc -> o(n) + o(n) {stack space + dp vector space}
public:
    int findans(vector<int> &v, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return v[0];
        }
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = v[n] + findans(v, n - 2, dp);
        int right = findans(v, n - 1, dp);
        return dp[n] = max(left, right);
    }
    int rob(vector<int> &v)
    {
        vector<int> dp(v.size(), -1);
        return findans(v, v.size() - 1, dp);
    }
};
// ----------------------------------  3  ---------------------------------------------
class Solution3_tabular
{ // tc -> (n) sc -> o(n) {dp vector space}
public:
    int rob(vector<int> &v)
    {
        vector<int> dp(v.size(), -1);
        dp[0] = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            int left = v[i];
            if (i > 1)
                left += dp[i - 2];
            int right = dp[i - 1];
            dp[i] = max(left, right);
        }
        return dp[v.size() - 1];
    }
};
// ----------------------------------  4  ---------------------------------------------
class Solution4_space_optimized
{ // tc -> (n) sc -> o(1) 
public:
    int rob(vector<int> &v)
    {
        int pre = v[0];
        int pre2 = -1;
        for (int i = 1; i < v.size(); i++)
        {
            int left = v[i];
            if (i > 1)
                left += pre2;
            int right = pre;
            int ctrMAX = max(left, right);
            pre2 = pre;
            pre = ctrMAX;
        }
        return pre;
    }
};