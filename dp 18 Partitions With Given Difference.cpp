#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define po pop_back
#define ll long long
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
int countPartitions(int n, int d, vector<int> &v) // just find the all the subset
{
    // s1+s2 = s
    // s1-s2 = d
    // s1+(s1-d) = s
    // s1=(s+d)/2 -> find (tsum+d)/2;
    int tsum = accumulate(v.begin(), v.end(), 0);
    if((tsum+d) % 2 != 0 )return 0;
    int t = (tsum + d) / 2;
    vector<vector<int>> dp(n,vector<int> (t+1,-1));
    return finds1(v.size() - 1, t, v,dp);
}
int main()
{
    int n, d;
    cin >> n >> d;
    vi v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << countPartitions(n, d, v);
}