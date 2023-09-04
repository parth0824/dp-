#include <bits/stdc++.h>
using namespace std;
 

class Solution {
public:  
    int findans1(int i,vector<int> &v){
        if(i >= v.size()) return 0; 
        return max(findans1(i+1,v),findans1(i+2,v) + v[i]);
    }
    int findans2(int i,vector<int> &v,vector<int> &dp){
        if(i >= v.size())return 0;
        if(dp[i] != -1)return dp[i];
        int l = findans2(i+1,v,dp);
        int r = findans2(i+2,v,dp) + v[i];
        return dp[i] = max(l,r);
    }
    int findans3(int n,vector<int> &v,vector<int> &dp){
        if(n == 0){
            return v[0];
        }
        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);
        for(int i=2;i<=n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+v[i]);
        }
        return dp[n];
    }
    int findans4(int n,vector<int> &v){
        if(n == 0){
            return v[0];
        }
        int prepre = v[0];
        int pre = max(v[0],v[1]);
        for(int i=2;i<=n;i++){
            int ctr = max(pre,prepre+v[i]);
            prepre = pre;
            pre = ctr;
        }
        return pre;
    }
    int rob(vector<int>& v) { 
        // return findans1(0,v);             worst solution pure recursion

        // vector<int> dp(v.size()+1,-1);
        // return findans2(0,v,dp);     dp -> top-down [ tc -> O(n)  sc -> O(n) + O(n)]

        // vector<int> dp(v.size()+1,-1);
        // return findans3(v.size()-1,v,dp);   //  dp -> bottom-up [ tc -> O(n)  sc -> O(n) ]

        return findans4(v.size()-1,v);   // best   tc -> O(n)   sc -> O(1)
    }
};



int main(){

return 0;
}