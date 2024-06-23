class Solution {
public:
    const int MOD = 1e9+7;
    unordered_map<int,int> req;
    vector<vector<int>> dp;
    int f(int ind, int count){
        if(ind==0){
            if(count==0) return 1;
            else return 0;
        }
        if(req.find(ind)!=req.end() && req[ind]!=count) return 0;
        if(dp[ind][count]!=-1) return dp[ind][count];
        int ans{};
        for(int k{}; k<=ind; k++){
            int inv = ind-k;
            if(inv<=count){
                ans = (ans + f(ind-1,count-inv))%MOD;
            }
        }
        return dp[ind][count] = ans;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        for(auto x : requirements){
            req[x[0]] = x[1];
        }
        dp.resize(n+3,vector<int>(410,-1));
        return f(n-1,req[n-1]);
    }
};