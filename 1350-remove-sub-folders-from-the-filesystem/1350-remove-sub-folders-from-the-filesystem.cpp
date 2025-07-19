class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        string prev = "";
        for (const string& f : folder) {
            if (prev.empty() || f.substr(0, prev.size()) != prev || f[prev.size()] != '/') {
                res.push_back(f);
                prev = f;
            }
        }
        return res;
    }
};