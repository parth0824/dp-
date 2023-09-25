#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define po pop_back
#define ll long long int
#define MOD 1000000007
int minimumDifference(vi &v)
{
    int k = accumulate(v.begin(), v.end(), 0);
    vector<vector<bool>> dp(v.size(), vector<bool>(k + 1, 0));

    for (int i = 0; i < v.size(); i++)
    {
        dp[i][0] = 1;
    }
    if (v[0] < k)
        dp[0][v[0]] = 1;
    for (int i = 1; i < v.size( ); i++)
    {
        for (int j = 1; j <= k + 1; j++)
        {
            bool take = 0, nottake = 0;
            if (v[i] <= j)
            {
                take = dp[i - 1][j - v[i]];
            }
            nottake = dp[i - 1][j];
            dp[i][j] = (take or nottake);
        }
    }  
    int ans = 1e9;
    for(int i=0;i<dp[dp.size()-1].size();i++){
        if(dp[dp.size()-1][i]){
            ans = min(ans,abs(i-(k-i)));  
        }
    } 
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vi v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << minimumDifference(v);
}