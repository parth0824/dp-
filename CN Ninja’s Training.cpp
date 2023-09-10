
/*

Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3  ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.


For example ->
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

input ->
2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
output ->
11
210
Explanation ->
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points.
On the second day, Ninja will do running and earn 3 merit points.
On the third day, Ninja will do fighting and earn 3 merit points.
The total merit point is 11 which is the maximum.
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points.
On the second day, Ninja will do fighting and earn 50 merit points.
On the third day, Ninja will learn new moves and earn 90 merit points.
The total merit point is 210 which is the maximum.
Hence, the answer is 210.

*/

#include <bits/stdc++.h> // greedy will not work in this, so we will try to find all the possibilities using recursion then optimize it uisng DP :)
using namespace std;
/*

//------------------------------ Pure recursive code [TLE mare ga :( ]-----------------------------------
int findans(int n, vector<vector<int>> &v, int pre){
    if (n == 0)return 0;
    int possibility1 = INT_MIN;
    int possibility2 = INT_MIN;
    int possibility3 = INT_MIN;
    if (pre != 1)possibility1 = findans(n - 1, v, 1) + v[n - 1][0];
    if (pre != 2)possibility2 = findans(n - 1, v, 2) + v[n - 1][1];
    if (pre != 3)possibility3 = findans(n - 1, v, 3) + v[n - 1][2];
    return max(possibility3, max(possibility2, possibility1));
}
int ninjaTraining(int n, vector<vector<int>> &v){
    int pre = 0;
    return findans(n, v, pre);
}
*/
//------------------------------ memoization ---------------------------------------------
/*
int ninjaTraining(int n, vector<vector<int>> &v){
    vector<vector<int>> dp(1 + n, vector<int>(4, -1));
    int pre = 0;
    return findans(n, v, pre, dp);
}
int findans(int n, vector<vector<int>> &v, int pre, vector<vector<int>> &dp){
    if (n == 0)return 0;
    if(dp[n][pre] != -1)return dp[n][pre];
    int possibility1 = INT_MIN;
    int possibility2 = INT_MIN;
    int possibility3 = INT_MIN;
    if (pre != 1)possibility1 = findans(n - 1, v, 1, dp) + v[n - 1][0];
    if (pre != 2)possibility2 = findans(n - 1, v, 2, dp) + v[n - 1][1];
    if (pre != 3)possibility3 = findans(n - 1, v, 3, dp) + v[n - 1][2];
    return dp[n][pre] =  max(possibility3, max(possibility2, possibility1));
}
*/
//------------------------------ tabulation ---------------------------------------------
int ninjaTraining(int n, vector<vector<int>> &v){
    vector<vector<int>> dp(1 + n, vector<int>(4, 0));
    for (int i = 1; i <= n; i++){
        for (int pre = 1; pre <= 3; pre++){
            int possibility1 = INT_MIN;
            int possibility2 = INT_MIN;
            int possibility3 = INT_MIN;
            if (pre != 1)possibility1 = dp[i - 1][1] + v[i - 1][0];
            if (pre != 2)possibility2 = dp[i - 1][2] + v[i - 1][1];
            if (pre != 3)possibility3 = dp[i - 1][3] + v[i - 1][2];
            dp[i][pre] = max(possibility3, max(possibility2, possibility1));
        }
    }
    return max(dp[n][1], max(dp[n][2], dp[n][3]));
}
void solve(){
    int n;cin >> n;
    vector<vector<int>> v;
    int x;
    for (int i = 0; i < n; i++){
        vector<int> help;
        for (int j = 0; j < 3; j++){
            cin >> x;
            help.push_back(x);
        }
        v.push_back(help);
    }
    cout << ninjaTraining(n, v) << endl;
}
int main(){
    int t;cin >> t;
    while (t--)solve();
    return 0;
}
