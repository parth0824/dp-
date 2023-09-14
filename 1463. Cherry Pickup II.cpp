#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define vvi vector<vector<int>>
/*
// ----------------------------------- backtracking solution [TLE] ------------------------------------

int ans = 0;
void findans2(int i, int j, vector<vector<int>> &v, int cherriesPicked)
{
    int n = v.size(), m = v[0].size();
    if (i < 0 || j < 0 || i > n || j >= m)
    {
        return;
    }
    if (i == n - 1)
    {
        int g = v[i][j];
        v[i][j] = 0;
        ans = max(ans, cherriesPicked + g);
        v[i][j] = g;
        return;
    }
    cherriesPicked += v[i][j];
    int x = v[i][j];
    v[i][j] = 0;
    findans2(i + 1, j, v, cherriesPicked);
    findans2(i + 1, j - 1, v, cherriesPicked);
    findans2(i + 1, j + 1, v, cherriesPicked);
    v[i][j] = x;
}
void findans1(int i, int j, vector<vector<int>> &v, int cherriesPicked)
{
    int n = v.size(), m = v[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return;
    }
    if (i == n - 1)
    {
        int g = v[i][j];
        v[i][j] = 0;
        findans2(0, m - 1, v, g + cherriesPicked);
        v[i][j] = g;
        return;
    }
    cherriesPicked += v[i][j];
    int x = v[i][j];
    v[i][j] = 0;
    findans1(i + 1, j, v, cherriesPicked);
    findans1(i + 1, j - 1, v, cherriesPicked);
    findans1(i + 1, j + 1, v, cherriesPicked);
    v[i][j] = x;
}
int cherryPickup(vector<vector<int>> &v)
{
    int cherriesPicked = 0;
    findans1(0, 0, v, cherriesPicked);
    return ans;
}
*/

// ------------------------------ memoization ---------------------------------------
int findans(int i, int j, int l, vvi &v, vector<vector<vector<int>>> &dp)
{
    if (j < 0 || j >= v[0].size() || l < 0 || l >= v[0].size())
        return INT_MIN;
    if (i == v.size() - 1)
    {
        if (j == l)
            return v[i][j];
        return v[i][j] + v[i][l];
    }
    if (dp[i][j][l] != -1)
        return dp[i][j][l];
    int cherries = 0;
    if (j == l)
        cherries += v[i][j];
    else
        cherries = v[i][j] + v[i][l];
    int f1 = findans(i + 1, j, l, v, dp);
    int f2 = findans(i + 1, j - 1, l, v, dp);
    int f3 = findans(i + 1, j + 1, l, v, dp);
    int f4 = findans(i + 1, j, l - 1, v, dp);
    int f5 = findans(i + 1, j - 1, l - 1, v, dp);
    int f6 = findans(i + 1, j + 1, l - 1, v, dp);
    int f7 = findans(i + 1, j, l + 1, v, dp);
    int f8 = findans(i + 1, j - 1, l + 1, v, dp);
    int f9 = findans(i + 1, j + 1, l + 1, v, dp);
    return dp[i][j][l] = cherries + max(f1, max(f2, max(f3, max(f4, max(f5, max(f6, max(f7, max(f8, f9))))))));
}
int cherryPickup(vector<vector<int>> &v)
{
    vector<vector<vector<int>>> dp(v.size(), vector<vector<int>>(v[0].size(), vector<int>(v[0].size(), -1)));
    return findans(0, 0, v[0].size() - 1, v, dp);
}

int cherryPickupTabulation(vector<vector<int>> & v){
    int n =  v.size();    
    int m =  v[0].size();  
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int j1 = 0; j1 < m; j1++){ // base case
        for (int j2 = 0; j2 < m; j2++){
            if (j1 == j2)dp[n - 1][j1][j2] =  v[n - 1][j1];
            else dp[n - 1][j1][j2] =  v[n - 1][j1] +  v[n - 1][j2];
        }
    } 
    for (int i = n - 2; i >= 0; i--){
        for (int j1 = 0; j1 < m; j1++){
            for (int j2 = 0; j2 < m; j2++){ 
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= +1; dj1++){ // 9 cases
                    for (int dj2 = -1; dj2 <= +1; dj2++){
                        int value = 0;
                        if (j1 == j2) value =  v[i][j1];
                        else value =  v[i][j1] +  v[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vvi v;
    int x;
    for (int i = 0; i < n; i++)
    {
        vi help;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            help.push_back(x);
        }
        v.push_back(help);
    }
    cout << cherryPickupTabulation(v);

    return 0;
}