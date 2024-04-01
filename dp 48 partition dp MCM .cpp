#include <bits/stdc++.h>
using namespace std;
int MCM(vector<int> &v)
{
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << MCM(v);
    return 0;
}