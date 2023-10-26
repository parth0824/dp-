#include <bits/stdc++.h>
using namespace std;
int findans(int i, bool buy, vector<int> &v)
{
    if (i >= v.size())
    {
        return 0;
    }
    if (buy)
    {
        return max(findans(i + 1, 0, v) - v[i], findans(i + 1, 1, v));
    }
    else
    {
        return max(findans(i + 2, 1, v) + v[i], findans(i + 1, 0, v));
    }
}
int maxProfit(vector<int> &v)
{
    return findans(0, 1, v);
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << maxProfit(v) << endl;
    return 0;
}