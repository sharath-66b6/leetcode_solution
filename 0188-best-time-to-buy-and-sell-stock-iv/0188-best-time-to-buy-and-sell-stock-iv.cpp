class Solution {
private:
    vector<vector<vector<int>>> dp;
    int solve(int i, int buy, vector<int>& p, int k){
        if(i == p.size() || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy){
            dp[i][buy][k] = max(-p[i] + solve(i+1, !buy, p, k),
                                solve(i+1, buy, p, k));
        }
        else{
            dp[i][buy][k] = max(p[i] + solve(i+1, !buy, p, k-1),
                                solve(i+1, buy, p, k));
        }
        return dp[i][buy][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        dp.assign(n+1, vector<vector<int>> (2, vector<int> (k+1,-1)));
        int ans = solve(0, 1, prices, k);
        
        return ans;
    }
};