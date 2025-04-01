class Solution {
public:
    vector<long long> dp;
    long long solve(int n, int i, vector<vector<int>>& questions){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        long long x = questions[i][0] + solve(n, i + questions[i][1]+1, questions);
        long long y = solve(n, i+1, questions);

        return dp[i] = max(x,y);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);
        return solve(n, 0, questions);
    }
};