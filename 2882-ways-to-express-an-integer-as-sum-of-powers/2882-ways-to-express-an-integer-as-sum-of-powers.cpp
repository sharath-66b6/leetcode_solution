class Solution {
private:
    int mod = 1e9+7;
    int solve(int num, int n, int x, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(num <= 0) return 0;

        if(dp[num][n] != -1) return dp[num][n];

        int take = 0;
        int not_take = solve(num-1, n, x, dp);
        
        int p = pow(num, x);
        if(p <= n){
            take = solve(num-1, n-p, x, dp);
        }
        dp[num][n] = (take + not_take)%mod;
        return dp[num][n];
    }
public:
    int numberOfWays(int n, int x) {
        int mx = 0;
        int p = pow(mx,x);
        while(p <= n){
            mx++;
            p = pow(mx,x);
        }

        vector<vector<int>> dp(mx+1, vector<int> (n+1,-1));
        return solve(mx, n, x, dp);
    }
};