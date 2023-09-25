#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define po pop_back
#define ll long long  
#define MOD 1000000007

// int findans(int i,int k,vector<int> &v){
//     if(k == 0){
//         return 1;
//     }
//     if(i == 0){
//         return v[0] == k;
//     }
//     int take = 0,nottake = 0;
//     if(v[i] <= k){
//         take = findans(i-1,k-v[i],v);
//     }
//     nottake = findans(i-1,k,v);
//     return take + nottake;
// }
// int findWays(vector<int> &v, int k)
// {
//     return findans(v.size()-1,k,v);
// }



ll int findans(int i,int k,vector<int> &v,vector<vi> &dp){
    if(k == 0){
        return 1;
    }
    if(i == 0){
        return v[0] == k;
    }
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    int nottake = findans(i-1,k,v,dp);
    ll int take = 0;
    if(v[i] <= k){
        take = findans(i-1,k-v[i],v,dp);
    }
    return dp[i][k] = (take + nottake)%MOD;
}
int findWays(vector<int> &v, int k)
{ 
    vector<vi> dp(v.size(),vi(k+1,-1));
    return findans(v.size()-1,k,v,dp);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vi v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << findWays(v, k);
}