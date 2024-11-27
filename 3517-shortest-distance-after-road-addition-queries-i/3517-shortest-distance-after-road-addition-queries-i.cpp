class Solution {
public:
    int sortest_path(vector<vector<int>> adj,int n)
    {
        vector<bool> visited(n+1, false);
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            
            int curr=q.front().first;
            int len=q.front().second;
            
            if(curr==n)
                return len;
            q.pop();

            if (visited[curr]) continue;
            visited[curr] = true;

            for(int i:adj[curr])
            {
                if(!visited[i])
                    q.push({i,len+1});
            }
        }
        return n;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            adj[i].push_back(i+1);
        }

        for(auto x:queries){
            adj[x[0]].push_back(x[1]);
            res.push_back(sortest_path(adj,n-1));
        }

        return res;
    }
};