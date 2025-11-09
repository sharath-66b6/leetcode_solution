class Solution {
private:
    bool iscycle(int i, vector<int>& vis, vector<int>& cycle, unordered_map<int, vector<int>>& g) {
        if (!vis[i]) {
            vis[i] = 1;
            cycle[i] = 1;

            for (auto n : g[i]) {
                if (!vis[n] && iscycle(n, vis, cycle, g))
                    return true;
                else if (cycle[n])
                    return true;
            }
        }
        cycle[i] = 0;
        return false;
    }

    void topoSort(int i, vector<int>& vis, stack<int>& s, unordered_map<int, vector<int>>& g) {
        vis[i] = 1;
        for (auto n : g[i]) {
            if (!vis[n]) {
                topoSort(n, vis, s, g);
            }
        }
        s.push(i);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> g;
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> cycle(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (iscycle(i, vis, cycle, g))
                return {};
        }

        stack<int> s;
        vis.assign(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                topoSort(i, vis, s, g);
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
