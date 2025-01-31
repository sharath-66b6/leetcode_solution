class Solution {
public:
    int n;
    vector<int> islandSize;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = id;
        int size = 1;
        for (auto& d : directions) {
            size += dfs(grid, i + d[0], j + d[1], id);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int islandId = 2, maxSize = 0;
        unordered_map<int, int> islandSize;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[islandId] = dfs(grid, i, j, islandId);
                    maxSize = max(maxSize, islandSize[islandId]);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1;

                    for (auto& d : directions) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            seen.insert(grid[x][y]);
                        }
                    }
                    
                    for (int id : seen) {
                        newSize += islandSize[id];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize == 0 ? n * n : maxSize;
    }
};
