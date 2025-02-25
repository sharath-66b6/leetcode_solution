class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int len = arr.size();
    unordered_map<int, vector<int>> adj;
    queue<int> pos;
    vector<bool> visited(len, false);
    
    pos.push(0);
    visited[0] = true;
    
    for (int i = 0; i < len; ++i)
        adj[arr[i]].push_back(i);
    
    for (int j = 0; !pos.empty(); ++j) {
        int count = pos.size();
        while (count--) {
            int idx = pos.front();
            pos.pop();
            if (idx == len - 1)
                return j;
            
            visited[idx] = true;
            int val = arr[idx];
            if (idx + 1 < len)
                adj[val].push_back(idx + 1);
            if (idx - 1 >= 0)
                adj[val].push_back(idx - 1);
            
            for (int next : adj[val]) {
                if (!visited[next])
                    pos.push(next);
            }
            adj[val].clear();
        }
    }
    
    return -1;
  }
};