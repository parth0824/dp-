#include <bits/stdc++.h>
using namespace std;
/*
// ---------------------------- recursivev {tle} -----------------------------
#include <bits/stdc++.h> 
bool findd(int n,int k,vector<int> &arr){
    if(k == 0){
        return true;
    }
    if(n == 0){
        if(arr[n] == k){
            return true;
        }
        return false;
    }
    bool take=false,nottake=false;
    if(arr[n] <= k){
        take = findd(n-1,k-arr[n],arr);
    }
    nottake = findd(n-1,k,arr);
    return take or nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return findd(n-1,k,arr);
}
*/

/*
// ---------------------------- memoization -----------------------------

#include <bits/stdc++.h> 
bool findd(int n,int k,vector<int> &arr, vector<vector<int>> &u){
    if(k == 0){
        return true;
    }
    if(n == 0){
        if(arr[n] == k){
            return true;
        }
        return false;
    } 
    if(u[n][k] != -1){
        return u[n][k];
    }
    bool take=false,nottake=false;
    if(arr[n] <= k){
        take = findd(n-1,k-arr[n],arr,u);
    }
    nottake = findd(n-1,k,arr,u);
    bool ans = take or nottake;
    u[n][k] = ans;
    return  ans;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> u(n,vector<int>(k+1,-1));
    return findd(n-1,k,arr,u);
}
*/


/*
// ---------------------------- tabulation -----------------------------
#include <bits/stdc++.h>  
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool take=false,nottake=false;
            if(arr[i] <= j){
                take = dp[i-1][j-arr[i]];
            }
            nottake = dp[i-1][j];  
            dp[i][j] = take or nottake; 
        }
    }
    return dp[n-1][k]; 
}  
*/




// ---------------------------- space optimization -----------------------------
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    vector<bool> pre(k+1,0),cur(k+1,0); 
    pre[0] = true;
    cur[0] = true;
    if(arr[0] <= k)
    pre[arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool take=false,nottake=false;
            if(arr[i] <= j){
                take = pre[j-arr[i]];
            }
            nottake = pre[j];  
            cur[j] = take or nottake; 
        }
        pre = cur;
    }
    return cur[k]; 
}  