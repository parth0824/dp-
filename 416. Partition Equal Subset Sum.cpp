#include <bits/stdc++.h>
using namespace std;
/*
// ----------------------------- recursive code ----------------------------
bool findtarget(int n, vector<int> &v, int target){
    if (target == 0) return true;
    if (n == 0) return v[0] == target;
    bool nottake = findtarget(n - 1, v, target);
    bool take = false;
    if (v[n] <= target) take = findtarget(n - 1, v, target - v[n]);
    return take || nottake;
}

bool canPartition(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2 != 0)
        return 0;
    int target = sum / 2;
    return findtarget(v.size() - 1, v, target);
}
*/

/*
// ----------------------------- memoization code ----------------------------
bool canPartition(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2 != 0)
        return 0;
    int target = sum / 2;
    vector<vector<int>> dp(v.size() + 1, vector<int>(target + 1, -1));
    return findtarget(v.size() - 1, v, target, dp);
}
bool findtarget(int n, vector<int> &v, int target, vector<vector<int>> &dp){
    if (target == 0)  return true;
    if (n == 0)  return v[0] == target;
    if (dp[n][target] != -1) return dp[n][target];
    bool nottake = findtarget(n - 1, v, target, dp);
    bool take = false;
    if (v[n] <= target) take = findtarget(n - 1, v, target - v[n], dp);
    return dp[n][target] = (take || nottake);
}
*/
// ----------------------------- tabulation code ----------------------------
bool canPartition(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2 != 0)
        return 0;
    int target = sum / 2;
    vector<vector<bool>> dp(v.size() + 1, vector<bool>(target + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = true;
    }
    dp[0][v[0]] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool nottake = dp[i - 1][j];
            bool take = false;
            if (v[i] <= j)
                take = dp[i - 1][j - v[i]];
            dp[i][j] = (take || nottake);
        }
    }
    return dp[v.size() - 1][target];
}
/*
space optimized 

bool canPartition(vector<int> &v){
    int totsum = accumulate(v.begin(), v.end(), 0); 
    if(totsum%2)return 0;
    vector<bool> pre(totsum+1,0),cur(totsum+1,0);
    pre[0] = 0;
    cur[0] = 0;
    pre[v[0]] = 1;
    for(int i=1;i<v.size();i++){
        for(int j=1;j<=totsum;j++){
            bool nottake = pre[j]; 
            bool take = 0;
            if(v[i] <= j) take = pre[j-v[i]]; 
            cur[j] = take or nottake;
        }
        pre = cur;
    }
    return cur[totsum/2];
}

*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, -1);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << canPartition(v);
}