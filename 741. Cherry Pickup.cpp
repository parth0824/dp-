#include <bits/stdc++.h>
using namespace std;
/*
// -------------------------------- backtrack code [TLE] --------------------------------------
int ans = 0;
void findans2(int i, int j, vector<vector<int>> &v, int &cherriesPicked)
{
    if (i < 0 || j < 0)
        return;
    if (v[i][j] == -1)
        return;
    if (i == 0 && j == 0)
    {
        bool chk = 0;
        if (v[i][j] == 1)
            cherriesPicked++, chk = 1, v[i][j] = 0;
        ans = max(ans, cherriesPicked);
        // cout << cherriesPicked << endl;
        if (chk)
            v[i][j] = 1, cherriesPicked--;
        return;
    }
    bool chk = 0;
    if (v[i][j] == 1)
        cherriesPicked++, chk = 1, v[i][j] = 0;
    findans2(i, j - 1, v, cherriesPicked);
    findans2(i - 1, j, v, cherriesPicked);
    if (chk)
        v[i][j] = 1, cherriesPicked--;
    return;
}
void findans1(int i, int j, vector<vector<int>> &v, int &cherriesPicked)
{
    if (i >= n || j >= n)
        return;
    if (v[i][j] == -1)
        return;
    if (i == n - 1 && j == n - 1)
    {
        bool chk = 0;
        if (v[i][j] == 1)
            cherriesPicked++, chk = 1, v[i][j] = 0;
        // cout << cherriesPicked << endl;
        findans2(i, j, v, cherriesPicked);
        if (chk)
            v[i][j] = 1, cherriesPicked--;
        return;
    }
    bool chk = 0;
    if (v[i][j] == 1)
        cherriesPicked++, chk = 1, v[i][j] = 0;
    findans1(i, j + 1, v, cherriesPicked);
    findans1(i + 1, j, v, cherriesPicked);
    if (chk)
        v[i][j] = 1, cherriesPicked--;
    return;
}
int cherryPickup(vector<vector<int>> &v)
{
    int cherriesPicked = 0;
    findans1(0, 0, v, cherriesPicked);
    return ans;
}
*/

/*
// -------------------------------- recursive code [TLE] --------------------------------------
int findans(int i, int j, int k, int l, vector<vector<int>> &v)
{
    int n = v.size();
    if (i >= n || j >= n || k >= n || l >= n || v[i][j] == -1 || v[k][l] == -1)
    {
        return INT_MIN;
    }
    if (i == n - 1 && j == n - 1)
    {
        return v[i][j];
    }

    int cherries = 0;
    if (i == k && j == l)
    {
        cherries += v[i][j];
    }
    else
    {
        cherries += v[i][j];
        cherries += v[k][l];
    }

    int f1 = findans(i, j + 1, k, l + 1, v);
    int f2 = findans(i + 1, j, k, l + 1, v);
    int f3 = findans(i + 1, j, k + 1, l, v);
    int f4 = findans(i, j + 1, k + 1, l, v);

    return cherries + max(f1, max(f2, max(f3, f4)));
}
int cherryPickup(vector<vector<int>> &v)
{
    int n = v.size();
    return findans(0, 0, 0, 0, v);
}
*/

// -------------------------------- memoization --------------------------------------

int findans(int i, int j, int k, int l, vector<vector<int>> &v, vector<vector<vector<vector<int>>>> &dp)
{
    int n = v.size();
    int m = v[0].size();
    if (i >= n || j >= m || k >= n || l >= m || v[i][j] == -1 || v[k][l] == -1)
        return INT_MIN;
    if (dp[i][j][k][l] != -1)
    {
        return dp[i][j][k][l];
    }
    if (i == n - 1 && j == n - 1)
        return v[i][j];
    int cherries = 0;
    if (i == k && j == l)
        cherries += v[i][j];
    else
        cherries += v[i][j], cherries += v[k][l];
    int f1 = findans(i, j + 1, k, l + 1, v, dp);
    int f2 = findans(i + 1, j, k, l + 1, v, dp);
    int f3 = findans(i + 1, j, k + 1, l, v, dp);
    int f4 = findans(i, j + 1, k + 1, l, v, dp);
    cherries += max(f1, max(f2, max(f3, f4)));
    dp[i][j][k][l] = cherries;
    return cherries;
}
int cherryPickup(vector<vector<int>> &v)
{
    int n = v.size();
    vector<vector<vector<vector<int>>>> dp(51, vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1))));
    int ans = max(0, findans(0, 0, 0, 0, v, dp));
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        vector<int> help;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            help.push_back(x);
        }
        v.push_back(help);
    }
    cout << cherryPickup(v);
}