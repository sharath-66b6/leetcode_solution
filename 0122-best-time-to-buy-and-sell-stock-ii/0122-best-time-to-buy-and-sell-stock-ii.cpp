class Solution {
private:
    vector<vector<int>> dp;
    int solve(int i, int buy, vector<int>& p){
        if(i == p.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            dp[i][buy] = max(-p[i] + solve(i+1, !buy, p), solve(i+1, buy, p));
        }
        else{
            dp[i][buy] = max(p[i] + solve(i+1, !buy, p), solve(i+1, buy, p));
        }
        return dp[i][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<int> (2, -1));
        return solve(0, 1, prices);
    }
};