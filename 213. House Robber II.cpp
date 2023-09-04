class Solution {
public:
    int findans(int n,vector<int> &v){
        if(n == 0){
            return v[0];
        }
        int prepre = v[0];
        int pre = max(v[0],v[1]);
        for(int i=2;i<=n;i++){
            int ctr = max(pre,prepre+v[i]);
            prepre = pre;
            pre = ctr;
        }
        return pre;
    }
    int rob(vector<int>& v) {
        if(v.size() == 1)return {v[0]};
        vector<int> t1 ,t2;
        for(int i=0;i<v.size();i++){
            if(i != 0)t1.push_back(v[i]);
            if(i != v.size()-1)t2.push_back(v[i]);
        }
        return max( findans(t1.size()-1,t1) ,findans(t2.size()-1,t2)   );
    }
};