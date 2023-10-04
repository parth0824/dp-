/*#include <bits/stdc++.h>
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
};*/
// striver power -> [subset1 - subset2] = target
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int finds1(int i, int k, vector<int> &v,vector<vector<int>>& dp)
{
    if (i == 0)
    {
        if(k == 0 && v[0] == 0)return 2;
        if(k == 0 || v[0] == k)return 1;
        return 0;
    }
    if(dp[i][k] != -1)return dp[i][k];
    int nottake = finds1(i-1,k,v,dp);
    int take =0;
    if(v[i] <= k)take = finds1(i-1,k-v[i],v,dp);
    return dp[i][k] = (take + nottake)%MOD;
}
int findTargetSumWays(vector<int> &v,int  d) // just find the all the subset
{ 
    int n = v.size();
        if(n == 1){
        if(abs(v[0]) == abs(d))return 1;
        return 0;
    }
    int tsum = accumulate(v.begin(), v.end(), 0);
    if((tsum+d) % 2 != 0 )return 0;
    int t = (tsum + d) / 2;
    if(t < 0)return 0;
    vector<vector<int>> dp(n,vector<int> (t+1,-1));
    return finds1(v.size() - 1, t, v,dp);
}
int main()
{
    int n;
    cin >> n; 
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x; 
        v.push_back(x);
    }
    cin >> x;
    cout << findTargetSumWays(v, x);
}