#include <bits/stdc++.h>
using namespace std;

int febonacci1(int n)
{
    if (n == 0 || n == 1)
        return n;
    int fib1 = febonacci1(n - 1);
    int fib2 = febonacci1(n - 2);
    int fib = fib1 + fib2;
    return fib;
}
int febonacci2(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = febonacci2(n - 1, dp) + febonacci2(n - 2, dp);
}
int febonacci3(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int febonacci4(int n)
{
    int fib1 = 0;
    int fib2 = 1;
    if (n == 0 || n == 1)
        return n;
    int ans = -1;
    for (int i = 2; i < n + 1; i++)
    {
        ans = fib1 + fib2;
        fib1 = fib2;
        fib2 = ans;
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    //-------------------------------------   1   -------------------------------------------
    // cout << febonacci1(n); // tc -> O(2^n) sc -> O(n)

    //-------------------------------------   2   -------------------------------------------
    // vector<int> dp(n + 1, -1);
    // cout << febonacci2(n, dp); // tc -> O(n) sc -> O(n) + O(n) {stack space + dp vector space}

    //-------------------------------------   3   -------------------------------------------
    // vector<int> dp(n + 1, -1);
    // cout << febonacci3(n, dp); // tc -> O(n) sc -> O(n) {dp vector space}

    //-------------------------------------   4   -------------------------------------------
    cout << febonacci4(n); // tc -> O(n) sc -> O(1) -> the best way
    return 0;
}