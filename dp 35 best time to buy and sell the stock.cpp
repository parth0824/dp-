#include <bits/stdc++.h>
using namespace std;
int maxProfit1(vector<int> &v) /// -> O(n^2)
{
    int n = v.size();
    int ans = 0;
    int minn = 1e9, maxx = -1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] < v[j])
            {
                ans = max(v[j] - v[i], ans);
            }
        }
    }
    return ans;
}
int maxProfit2(vector<int> &v) /// -> O(n)
{
    if (v.size() == 1)
        return 0;
    int n = v.size();
    int ans = 0;
    int minn = 1e9, maxx = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < minn)
        {
            minn = v[i];
        }
        ans = max(ans, v[i] - minn);
    }
    return ans;
}
int findans(int i, vector<int> &v)
{
    //  3 options -> buy or sell or dont do anything
    

}
int maxProfit(vector<int> &v)
{
    return findans(v.size() - 1, v);
}
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
    cout << maxProfit(v) << endl;
    return 0;
}