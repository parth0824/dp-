#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob1(vector<int> &v, int length, int chk)
    {
        int pre = v[chk];
        int pre2 = 0;
        for (int i = 1 + chk; i < length; i++)
        {
            int left = v[i];
            if (i > 1)
                left += pre2;
            int right = pre;
            int ctrMAX = max(left, right);
            pre2 = pre;
            pre = ctrMAX;
        }
        return pre;
    }
    int rob(vector<int> &v)
    {
        if (v.size() == 1)
            return v[0];
        int r1 = rob1(v, v.size() - 1, 0);
        int r2 = rob1(v, v.size(), 1);
        return max(r1, r2);
    }
};