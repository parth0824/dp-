#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findans(int i, int k, vector<int> &v, map<pair<int, int>, int> &dp)
    {
        if (i == -1)
        {
            return k == 0;
        } 
        if (dp.count({i, k}))
        {
            return dp[{i, k}];
        }
        int take = 0, nottake = 0;
        take = findans(i - 1, k - v[i], v, dp);
        nottake = findans(i - 1, k + v[i], v, dp);
        return dp[{i, k}] = take + nottake;
    }
    int findTargetSumWays(vector<int> &v, int k)
    {
        map<pair<int, int>, int> dp; // to take -ve index we use map because in vector we can not have -ve index 
        return findans(v.size() - 1, k, v, dp);
    }
};