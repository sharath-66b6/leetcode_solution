class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(words[i] != words[j] && words[j].find(words[i]) != string::npos)
                    res.insert(words[i]);
            }
        }
        vector<string> v(res.begin(), res.end());
        return v;
    }
};