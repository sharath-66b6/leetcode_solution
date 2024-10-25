class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> v;
        sort(folder.begin(),folder.end());
        string x="";
        for(string s:folder)
        {
            if(x.empty() || s.find(x+"/") != 0)
            {
                v.push_back(s);
                x=s;
            }
                
        }
        return v;
    }
};