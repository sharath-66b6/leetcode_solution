class Solution {
public:
    void dfs(int node, stack<int>& st, vector<int>& vis, map<int, vector<int>> adj){
        vis[node]=1;
        for(int n:adj[node]){
            if(!vis[n]){
                dfs(n,  st, vis, adj);
            }
            
        }
        st.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        for(auto e:prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> ind(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
                ind[it]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int it:adj[node]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        if(topo.size() == numCourses) return true;
        return false;
    }
};