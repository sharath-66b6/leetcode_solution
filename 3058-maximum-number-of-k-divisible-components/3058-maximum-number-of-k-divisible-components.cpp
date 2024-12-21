class Solution {
public:
    map<int, vector<int>> adj;
    vector<int> val;
    int res = 0, x;

    long long dfs(int cur, int p) {
        long long total = val[cur];
        for (auto child : adj[cur]) {
            if (child != p)
                total += dfs(child, cur);
        }
        if (total % x == 0)
            res++;
        return total;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        val = values;
        x = k;
        for (const auto& edge : edges) {
            int i = edge[0], j = edge[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        dfs(0, -1);
        return res;
    }
};
