class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, int j, string &s) {
        if (i >= n || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = 1 + solve(i + 1, j - 1, s);

        return dp[i][j] = max(solve(i + 1, j, s), solve(i, j - 1, s));
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, s);
    }
};


