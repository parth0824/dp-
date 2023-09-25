#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define po pop_back
#define ll long long
#define MOD 1000000007
int countPartitions(int n, int d, vector<int> &v)
{
}
int main()
{
    int n, d;
    cin >> n >> d;
    vi v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << countPartitions(n, d, v);
}