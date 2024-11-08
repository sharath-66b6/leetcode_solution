class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        vector<int> nodes(n,0);

        for (const auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }

        for(int i=0;i<n;++i){
            if (hascycle(graph, i, nodes)) {
                return false;
            }
        }

        return true;
    }

private:
        bool hascycle(const vector<vector<int>>& graph, int u, vector<int>& states)
    {
        if(states[u] == -1)
            return true;
        if(states[u] == 1)
            return false;
        
        states[u]=-1;
        for(int v:graph[u])
        {
            if(hascycle(graph, v, states))
                return true;
        }
        states[u]=1;
        return false;
    }
};