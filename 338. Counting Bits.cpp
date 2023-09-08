#include <bits/stdc++.h>
using namespace std;




// best solution tc -> O(n) better than DP solution 
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         if(n == 0)return {0};
//         if(n == 1)return {0,1};
//         vector<int> ans = {0,1};
//         for(int i=2;i<=n;i++){ 
//             if(i % 2 == 0) ans.push_back(ans[i / 2]);
//             else ans.push_back(ans[i / 2]+1);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int findbit(int i){
        int bit = __builtin_popcount (i);
        return bit;
    }
    vector<int> countBits(int n) {
        vector<int> ans (n+1,0);
        for(int i=0;i<n+1;i++){
            int funans = findbit(i);
            ans[i] = funans;
        }
        return ans;
    }
};