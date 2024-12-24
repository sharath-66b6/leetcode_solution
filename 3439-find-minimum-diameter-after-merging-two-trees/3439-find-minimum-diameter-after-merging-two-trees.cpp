class Solution {
public:
        pair<int, int> bfs(int start, const vector<vector<int>>& tree) {
        int n = tree.size();
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthestNode = start, maxDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : tree[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return {farthestNode, maxDist};
    }

    int findDiameter(const vector<vector<int>>& tree) {
        auto [farthestNode, _] = bfs(0, tree);
        auto [_, diameter] = bfs(farthestNode, tree);
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        vector<vector<int>> tree1(n1), tree2(n2);
        for (const auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        int dia1 = findDiameter(tree1);
        int dia2 = findDiameter(tree2);


        return max({dia1, dia2, ((dia1+1)/2 + (dia2+1)/2 + 1)});
    }
};