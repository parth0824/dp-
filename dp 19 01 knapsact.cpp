#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define po pop_back
#define ll long long
#define MOD 1000000007

// memoization
int findknapsack(vector<int> w, vector<int> v, int i, int mw, vector<vi> &dp){
    if (i == 0){
        if (w[0] <= mw)return v[0];
        return 0;
    }
    if (dp[i][mw] != -1)return dp[i][mw];
    int take = -1e9, nottake = -1e9;
    if (w[i] <= mw) take = findknapsack(w, v, i - 1, mw - w[i], dp) + v[i];
    nottake = findknapsack(w, v, i - 1, mw, dp);
    return dp[i][mw] = (max(take, nottake)) % MOD;
}
// tabulation
int knapsack(vector<int> w, vector<int> v, int n, int mw){ 
    vector<vector<int>> dp(n, vector<int>(mw + 1, 0)); 
    for(int i=w[0];i<=mw;i++)dp[0][i] = v[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=mw;j++){
            int take = -1e9, nottake = -1e9;
            if (w[i] <= j) take = dp[i-1][j-w[i]] + v[i]; 
            nottake = dp[i-1][j]; 
            dp[i][j] = (max(take, nottake)) % MOD;
        }
    } 
    return dp[n-1][mw];
}
// space optimize
int knapsack(vector<int> w, vector<int> v, int n, int mw){  
    vector<int> pre(mw+1,0),ctr(mw+1,0);
    for(int i=w[0];i<=mw;i++)pre[i] = v[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=mw;j++){
            int take = -1e9, nottake = -1e9;
            if (w[i] <= j) take = pre[j-w[i]] + v[i]; 
            nottake = pre[j]; 
            ctr[j] = (max(take, nottake)) % MOD;
        }
        pre = ctr;
    } 
    return pre[mw];
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> w(n, -1), v(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        w[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    int mwgt;
    cin >> mwgt;
    cout << knapsack(w, v, n, mwgt);
    return 0;
}