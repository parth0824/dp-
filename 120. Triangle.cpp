#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define ll long long int
#define pb push_back
#define vi vector<int>
/*
2
3 4
6 5 7
4 1 8 3
*/
int findans(int i, int j, vvi &v)
{

}
int minimumTotal(vector<vector<int>> &v)
{
    return findans(v.size() - 1, v[v.size() - 1].size() - 1, v);
}
int main()
{
    int n;
    cin >> n;
    vvi v;
    int x;
    for (int i = 0; i < n; i++)
    {
        vi help;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            help.pb(x);
        }
        v.pb(help);
    }
    cout << minimumTotal(v);
    return 0;
}


/*
                breakfast       lunch       snacks      dinner
sunday             ok            na           ok          ok                3
monday             ok            ok           ok          ok                4
tuesday          ok/notok        ok           n-          ok                3
wednesday          ok            |            ok          ok                3
thursday           ok            -            n-          ok                2.5
friday             ok            ok           n-           |                2.5
saturday           ok            |            -         ok/notok            1.5

*/