class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mp;
        vector<int> ans;
        map<int,int> s;
        for(auto q:queries){
            if(mp[q[0]]){
                s[mp[q[0]]]--;
                if(s[mp[q[0]]] == 0)
                    s.erase(mp[q[0]]);
            }

            mp[q[0]] = q[1];
            s[q[1]] += 1;
            ans.push_back(s.size());
        }

        return ans;        
    }
};