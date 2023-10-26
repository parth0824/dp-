#include <bits/stdc++.h>
using namespace std;
// -------------------- tle -> exponential time -> O(n) space
// int findans(int i, int pre, vector<int> &v)
// {
//     if (i == v.size())
//     {
//         return 0;
//     }
//     if (pre == -1 || v[pre] < v[i])
//     {
//         return max(findans(1 + i, i, v) + 1, findans(i + 1, pre, v));
//     }
//     else
//     {
//         return findans(i + 1, pre, v);
//     }
// }
// int lengthOfLIS(vector<int> &v)
// {
//     return findans(0, -1, v);
// }




// tc-> O(n*n) sc O(n)+O{n}
// int findans(int i, int pre, vector<int> &v, vector<vector<int>> &dp)
// {
//     if (i == v.size())
//     {
//         return 0;
//     }
//     if (dp[i][pre+1] != -1)
//     {
//         return dp[i][pre+1];
//     }
//     if (pre == -1 || v[pre] < v[i])
//     {
//         return dp[i][pre+1] = max(findans(1 + i, i, v, dp) + 1, findans(i + 1, pre, v, dp));
//     }
//     else
//     {
//         return dp[i][pre+1] = findans(i + 1, pre, v, dp);
//     }
// }
// int lengthOfLIS(vector<int> &v)
// {
//     vector<vector<int>> dp(v.size(), vector<int>(v.size()+1, -1));
//     int ans = findans(0, -1, v, dp);
//     for(auto i : dp){for(auto j : i)cout<<j<<" ";cout<<endl;}
//     return ans;
// }



// tc-> O(n*n) | sc -> O(n) 
int lengthOfLIS(vector<int> &v){
    vector<vector<int>> dp(v.size()+1, vector<int>(v.size()+1, 0)); 
    for (int i = v.size()-1; i >= 0; i--){
        for (int pre = i-1; pre >= -1; pre--){
            if (pre == -1 || v[i] > v[pre]) dp[i][pre+1] = max(dp[i + 1][i+1] + 1, dp[i + 1][pre+1]);
            else dp[i][pre+1] = dp[i + 1][pre+1];
        }
    }  
    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << lengthOfLIS(v) << endl;
    return 0;
}