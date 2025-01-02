class Solution {
public:
    bool isvowel(char ch) { return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<bool> res;
        for(auto s:words)
        {
            if(isvowel(s[0]) && isvowel(s[s.size()-1]))
                res.push_back(true);
            else
                res.push_back(false);
        }

        vector<int> ans(words.size());
        ans[0] = (res[0])? 1:0;
        for(int i=1;i<words.size();i++)
        {
            if(res[i])
                ans[i] = ans[i-1] + 1;
            else
                ans[i] = ans[i-1];
        }

        vector<int> result;
        for(auto q:queries){
            if(q[0] == 0)
                result.push_back(ans[q[1]]);
            else
            {
                result.push_back(ans[q[1]] - ans[q[0]-1]);
            }
        }
        return result;
    }
};