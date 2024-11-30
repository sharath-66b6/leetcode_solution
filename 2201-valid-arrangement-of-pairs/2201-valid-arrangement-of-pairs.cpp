class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adj;
        unordered_map<int, int> indeg, outdeg;

        for(auto pair: pairs)
        {
            int st=pair[0], en=pair[1];
            adj[st].push_back(en);
            outdeg[st]++;
            indeg[en]++;
        }

        vector<int> res;
        int st=-1;
        for(auto x:outdeg)
        {
            int node=x.first;
            if(outdeg[node] == (indeg[node] + 1))
            {
                st=node;
                break;
            }
        }
        if(st == -1) st=pairs[0][0];

        stack<int> stack;
        stack.push(st);

        while(!stack.empty()){
            int node=stack.top();
            if(!adj[node].empty()){
                int nxt = adj[node].front();
                adj[node].pop_front();
                stack.push(nxt);
            }
            else{
                res.push_back(node);
                stack.pop();
            }
        }

        reverse(res.begin(),res.end());

        vector<vector<int>> result;
        for(int i=1;i<res.size();i++)
        {
            result.push_back({res[i-1], res[i]});
        }

        return result;
    }
};