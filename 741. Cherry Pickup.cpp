#include <bits/stdc++.h>
using namespace std;
int findans1(int i, int j, vector<vector<int>> &v)
{
    if (i >= v.size() || j >= v.size())
        return 0;
    if (v[i][j] == -1)
        return 0;
    if (i == v.size() - 1 && j == v.size() - 1)
    {
        // 
    }
    int right = findans1(i, j + 1, v);
    int down = findans1(i + 1, j, v);
    return down + right;
}
int cherryPickup(vector<vector<int>> &v)
{
    int zerozeroTOnn = findans1(0, 0, v);
    return zerozeroTOnn;
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