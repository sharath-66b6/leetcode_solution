class Solution {
public:
    vector<vector<int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
    

        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == n - 1 && c == n - 1) {
                return t;
            }
            for (const auto& dir : dir) {
                int a = r + dir[0], b = c + dir[1];
                if (a < 0 || b < 0 || a == n || 
                    b == n || visit.count({a, b})) {
                    continue;
                }
                visit.insert({a, b});
                minHeap.push({
                    max(t, grid[a][b]), a, b
                });
            }
        }
        return n * n;
    }
};