class Solution {
    public:
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(
            27, vector<vector<int>>(27, vector<int>(word.length(), -1)));
        return minimumDistance(word, 26, 26, 0, dp);
    }

    private:
    int minimumDistance(string word, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (k == word.length())
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        const int c = word[k] - 'A';
        const int moveLeft = dist(i, c) + minimumDistance(word, c, j, k + 1, dp);
        const int moveRight = dist(j, c) + minimumDistance(word, i, c, k + 1, dp);
        return dp[i][j][k] = min(moveLeft, moveRight);
    }

    int dist(int a, int b) {
        if (a == 26)
            return 0;
        const int x1 = a / 6;
        const int y1 = a % 6;
        const int x2 = b / 6;
        const int y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
