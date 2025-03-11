class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0;
        vector<int> res = {-1, -1, -1};
        int ans = 0;
        for(int i=0; i<n; i++){
            res[s[i] - 'a'] = i;
            ans += 1 + min({res[0], res[1], res[2]});
        }
        return ans;
    }
};