class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,vector<int>> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }

        int ans = 0;
        for(auto x:mp)
        {
            vector<int> v = x.second;
            if(v.size() >= 2)
            {
                set<char> st;
                for(int i=v[0]+1; i<v[v.size()-1];i++)
                    st.insert(s[i]);
                ans += st.size();
            }
        }
        return ans;
    }
};