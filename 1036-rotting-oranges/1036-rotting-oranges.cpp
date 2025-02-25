class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = g.size();
        int c = g[0].size();

        auto hasRot = [&](int x, int y) {
            for (const auto& dir : d) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == 2)
                    return true;
            }
            return false;
        };

        int t = 0;

        while (true) {
            vector<vector<int>> u = g;
            bool ch = false;

            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (g[i][j] == 1 && hasRot(i, j)) {
                        u[i][j] = 2;
                        ch = true;
                    }
                }
            }

            if (!ch) break;
            g = u;
            ++t;
        }

        for (const auto& row : g) {
            if (find(row.begin(), row.end(), 1) != row.end()) {
                return -1;
            }
        }

        return t;
    }
};
