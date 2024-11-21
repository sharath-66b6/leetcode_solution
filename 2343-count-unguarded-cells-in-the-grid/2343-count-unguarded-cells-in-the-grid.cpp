class Solution {
public:
    void help(vector<vector<int>>& res, int m, int n, int i, int j) {
        for (int x = i - 1; x >= 0; x--) {
            if (res[x][j] == -1 || res[x][j] == 2) break; 
            res[x][j] = 0;
        }
        for (int x = i + 1; x < m; x++) {
            if (res[x][j] == -1 || res[x][j] == 2) break;
            res[x][j] = 0;
        }
        for (int y = j - 1; y >= 0; y--) {
            if (res[i][y] == -1 || res[i][y] == 2) break;
            res[i][y] = 0;
        }
        for (int y = j + 1; y < n; y++) {
            if (res[i][y] == -1 || res[i][y] == 2) break;
            res[i][y] = 0;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> res(m, vector<int>(n, 1));

        for (auto& w : walls) {
            res[w[0]][w[1]] = -1;
        }

        for (auto& g : guards) {
            res[g[0]][g[1]] = 2;
        }

        for (auto& g : guards) {
            help(res, m, n, g[0], g[1]);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j] == 1) count++;
            }
        }

        return count;
    }
};
