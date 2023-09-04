#include <bits/stdc++.h> 
using namespace std;
int findans3(int n,vector<int> &h){
    int pre1 = 0;
    int pre2 = 0;
    for(int i=1;i<n;i++){ 
        int l,r;
        l=r=INT_MAX; 
        l = pre1 + abs(h[i] - h[i-1]);
        if(i!=1)
        r = pre2 + abs(h[i] - h[i-2]);
        pre2=pre1;
        pre1 = min(l,r);
    }
    return pre1;

}
int findans2(int n,vector<int> h){
    vector<int> dp(n,-1);
    dp[0] = 0; 
    for(int i=1;i<n;i++){ 
        int l,r;
        l=r=INT_MAX; 
        l = dp[i-1] + abs(h[i] - h[i-1]);
        if(i!=1)
        r = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(l,r);
    }
    return dp[n-1];
}


int findans1(int i,vector<int> &dp,vector<int> &h){
    if(i <= 0){
        return 0;
    }

 
    if(dp[i]!=-1)return dp[i];
    int l,r;
    l=r=INT_MAX; 
    l = findans1(i-1,dp,h) + abs(h[i] - h[i-1]);
    if(i-2 >= 0)
    r = findans1(i-2,dp,h) + abs(h[i] - h[i-2]);

    return dp[i]=min(l,r);







}
int frogJump(int n, vector<int> &h){    
    // vector<int> dp(n+1,-1);
    // return findans1(n-1,dp,h);

    // return findans2(n,h);

    return findans3(n,h);


}



















// for kth jump
#include <bits/stdc++.h> 
int findans(int n,vector<int> &h,int k,vector<int> &dp){
    if(n <= 0)return 0;
    if(dp[n]!=-1)return dp[n];
    int y = INT_MAX;
    for(int i=1;i<=k;i++){
        int x = INT_MAX;
        if(n-i >= 0)        
        x = findans(n-i,h,k,dp) + abs(h[n-i] - h[n]);
        y = min(y,x);       
    }
    return dp[n] = y;
}
int frogJump(int n, vector<int> &h){
    int k = 2; // atmost kth jump can be taken
    vector<int> dp(n+1,-1);
    return findans(n-1,h,k,dp);
}