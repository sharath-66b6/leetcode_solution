class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (!hasPath(grid, 0, 0))
        return true;
        grid[0][0] = 1;
        return !hasPath(grid, 0, 0);
    }

private:
    bool hasPath(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || j == grid[0].size())
        return false;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return true;
        if (grid[i][j] == 0)
        return false;

        grid[i][j] = 0;
        return hasPath(grid, i + 1, j) || hasPath(grid, i, j + 1);
    }
};
