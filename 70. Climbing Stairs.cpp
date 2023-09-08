#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findans1(int n,vector<int> &dp){  // dp top-down -> tc -> O(n) , sp -> o(n) + O(n)
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int firststep = findans1(n-1,dp);
        int secondstep = findans1(n-2,dp);
        return dp[n] = firststep+secondstep;
    }

    void findans2(int n,vector<int> &dp){ // dp bottom-up -> tc -> O(n) , sp -> O(n)
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }



    }
 
    int findans3(int n){    // dp bottom-up -> tc -> O(n) , sp -> O(1) ---- the best ----
        int prepre = 1;
        int pre = 1;
        int ans = 1;
        for(int i=2;i<=n;i++){
            ans = prepre + pre;
            prepre = pre;
            pre = ans;
        }
        return ans;
    }
    int climbStairs(int n) {

        /* findans1

        vector<int> dp(n+1,-1);
        dp[1] = 1;
        int x = findans(n,dp);
        return dp[n];

        */


        /* findans2

        vector<int> dp(n+1,-1);

        findans2(n,dp);

        return dp[n];

        */ 

        /* findans3*/

        return findans3(n); // best fun3



        





    }
};