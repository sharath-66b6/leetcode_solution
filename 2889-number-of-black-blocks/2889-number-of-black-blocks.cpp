class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ans(5);
        unordered_map<long, int> count;

        for (auto& c : coordinates) {
        int x = c[0];
        int y = c[1];
        for (long i = x; i < x + 2; i++)
            for (long j = y; j < y + 2; j++)
                if (i - 1 >= 0 && i < m && j - 1 >= 0 && j < n)
                    ++count[i * n + j];
                }

        for (auto& [_, freq] : count)
        ++ans[freq];

        ans[0] = (m - 1L) * (n - 1L) - accumulate(ans.begin(), ans.end(), 0L);
        return ans;
    }
};