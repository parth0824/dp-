#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &v)
{
    int sum = accumulate(v.begin(),v.end(),0);
    if(sum % 2 != 0){
        return 0;
    }
    int target = sum/2;
    vector<bool> pre(target+1,0),ctr(target+1,0);
    if(v[0] <= target)pre[v[0]] = 1;
    pre[0] = ctr[0] = 1;
    for(int i=1;i<v.size();i++){
        for(int j=1;j<target+1;j++){
            bool take =0,nottake= 0;
            if(v[i] <= j){
                take = pre[j-v[i]];
            }
            nottake = pre[j];
            ctr[j] = take or nottake;
        }
        pre = ctr;
    }
    return pre[target];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    cout << canPartition(v);
}