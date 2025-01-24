class Solution {
public:
    map<int,bool> safe;
    bool dfs(int i,vector<vector<int>>& graph){
        if(safe.count(i))
            return safe[i];
        safe[i] = false;
        for(auto x:graph[i])
        {
            if(!dfs(x, graph))
                return safe[i];
            
        }
        safe[i] = true;
        return safe[i];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(dfs(i,graph))
                res.push_back(i);
        }
        return res;
    }
};