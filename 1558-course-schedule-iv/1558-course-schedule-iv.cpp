class Solution {
public:
    void dfs(const vector<vector<int>>& graph, int u, vector<bool>& used) {
        for (const int v : graph[u]) {
        if (used[v])
            continue;
        used[v] = true;
        dfs(graph, v, used);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> mp(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            mp[prerequisites[i][0]].push_back( prerequisites[i][1] );
        }

        vector<vector<bool>> dp(numCourses, vector<bool>(numCourses));
        for(int i=0;i<numCourses;i++)
        {
            dfs(mp, i, dp[i]);
        }

        vector<bool> ans;
        for(auto q:queries)
        {
            vector<bool> visited(numCourses, false);
            ans.push_back(dp[q[0]][q[1]]);
        }

        return ans;
    }
};