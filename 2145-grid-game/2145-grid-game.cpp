class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        long ans = LONG_MAX;
        long sumr0 = accumulate(grid[0].begin(), grid[0].end(), 0L);
        long sumr2 = 0;

        for (int i = 0; i < n; ++i) {
            sumr0 -= grid[0][i];
            ans = min(ans, max(sumr0, sumr2));
            sumr2 += grid[1][i];
        }

        return ans;
    }
};