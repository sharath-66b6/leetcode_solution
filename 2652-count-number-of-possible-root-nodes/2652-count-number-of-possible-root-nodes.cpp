class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int ans = 0;
        const int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        vector<unordered_set<int>> guessGraph(n);
        vector<int> parent(n);

        for (const vector<int>& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (const vector<int>& guess : guesses) {
            const int u = guess[0];
            const int v = guess[1];
            guessGraph[u].insert(v);
        }

        dfs(graph, 0, -1, parent);

        int correctGuess = 0;
        for (int i = 1; i < n; ++i)
            if (guessGraph[parent[i]].contains(i))
                ++correctGuess;

        reroot(graph, 0,-1, correctGuess, guessGraph, k, ans);
        return ans;
    }

    void dfs(const vector<vector<int>>& graph, int u, int prev, vector<int>& parent) {
        parent[u] = prev;
        for (const int v : graph[u])
            if (v != prev)
                dfs(graph, v, u, parent);
    }

    void reroot(const vector<vector<int>>& graph, int u, int prev, int correctGuess, const vector<unordered_set<int>>& guessGraph, const int& k, int& ans) {
        if (u != 0) {
        
        if (guessGraph[u].contains(prev))
            ++correctGuess;

        if (guessGraph[prev].contains(u))
            --correctGuess;
        }
        if (correctGuess >= k)
            ++ans;
        for (const int v : graph[u])
            if (v != prev)
                reroot(graph, v, u, correctGuess, guessGraph, k, ans);
    }
};
