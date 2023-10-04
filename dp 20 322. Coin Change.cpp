// recursive code tc and sc is exponential
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
/*
// memoization
int findmincoins(int i, int k, vector<int> &v, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (k % v[0] == 0)
            return k / v[0];
        return 1e9;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    int take = 1e9, nottake = 1e9;
    if (v[i] <= k)
    {
        take = 1 + findmincoins(i, k - v[i], v, dp);
    }
    nottake = findmincoins(i - 1, k, v, dp);
    return dp[i][k] = (min(take, nottake)) % MOD;
}
int coinChange(vector<int> &v, int k)
{
    if (k == 0)
        return 0;
    if (v.size() == 1)
    {
        int mo = k % v[0];
        if (mo == 0)
            return k / v[0];
        return -1;
    }
    vector<vector<int>> dp(v.size(), vector<int>(k + 1, -1));
    int ans = findmincoins(v.size() - 1, k, v, dp);
    if (ans == 1e9)
        return -1;
    return ans;
}
*/
// tabulation
int coinChange(vector<int> &v, int k){
    if (k == 0) return 0;
    if (v.size() == 1){
        int mo = k % v[0];
        if (mo == 0)return k / v[0];
        return -1;
    }

    // if (i == 0) {
    //     if (k % v[0] == 0)  return k / v[0];
    //     return 1e9;
    // }

 
    // for(int i=0;i<v.size();i++){ ------------------------------> wrong base case 
    //     if(k % v[i] == 0) dp[0][v[i]] = k/v[i];
    //     else dp[0][v[i]] = 1e9;
    // }

    vector<vector<int>> dp(v.size(), vector<int>(k + 1, 0));
    for(int t=0;t<k+1;t++){
        if(t%v[0] == 0) dp[0][t] = t/v[0];
        else dp[0][t] = 1e9;
    } 
    for(int i=1;i<v.size();i++){
        for(int j=0;j<k+1;j++){
            int take = 1e9, nottake = 1e9;
            if (v[i] <= j)take = 1 + dp[i][j-v[i]];//  findmincoins(i, k - v[i], v, dp);
            nottake = dp[i-1][j];// findmincoins(i - 1, k, v, dp);
            dp[i][j] = (min(take, nottake)) % MOD;
        }
    } 
    return dp[v.size()-1][k];


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
    cout << coinChange(v, k);
}