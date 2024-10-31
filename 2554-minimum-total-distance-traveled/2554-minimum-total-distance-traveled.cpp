class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0;  
        }

        for (int i = 1; i <= n; ++i) {  
            for (int j = 1; j <= m; ++j) {  
                dp[i][j] = dp[i][j - 1];  

                long long sum = 0;
                for (int k = 1; k <= min(i, factory[j - 1][1]); ++k) {  
                    sum += abs(factory[j - 1][0] - robot[i - k]);
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + sum);
                    }
                }
            }
        }

        return dp[n][m];
    }
};