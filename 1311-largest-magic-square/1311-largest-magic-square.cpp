class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;
        for (int j = 0; j < k; ++j)
            target += grid[r][c + j];

        for (int i = 0; i < k; ++i) {
            int rowSum = 0;
            for (int j = 0; j < k; ++j)
                rowSum += grid[r + i][c + j];
            if (rowSum != target)
                return false;
        }

        for (int j = 0; j < k; ++j) {
            int colSum = 0;
            for (int i = 0; i < k; ++i)
                colSum += grid[r + i][c + j];
            if (colSum != target)
                return false;
        }

        int mainDiag = 0, antiDiag = 0;
        for (int i = 0; i < k; ++i) {
            mainDiag += grid[r + i][c + i];
            antiDiag += grid[r + i][c + k - 1 - i];
        }

        return mainDiag == target && antiDiag == target;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxK = min(n, m);

        for (int k = maxK; k >= 1; --k) {
            for (int r = 0; r <= n - k; ++r) {
                for (int c = 0; c <= m - k; ++c) {
                    if (check(grid, r, c, k)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};
