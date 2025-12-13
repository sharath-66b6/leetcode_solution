class Solution {
private:
    vector<vector<vector<int>>> dp;
    int solve(int i, int buy, int cap, vector<int>& prices){
        if(i == prices.size() || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if(buy){
            dp[i][buy][cap] = max(-prices[i] + solve(i+1, 0, cap, prices), solve(i+1, 1, cap, prices));
        }
        else{   //sale
            dp[i][buy][cap] = max(prices[i] + solve(i+1, 1, cap-1, prices), solve(i+1, 0, cap, prices));
        }
        return dp[i][buy][cap];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<vector<int>> (2, vector<int> (3,-1)));

        return solve(0, 1, 2, prices);
    }
};