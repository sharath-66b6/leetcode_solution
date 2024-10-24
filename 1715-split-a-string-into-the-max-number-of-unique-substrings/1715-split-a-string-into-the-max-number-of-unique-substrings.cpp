class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> set;
        return backtrack(s,0,set);
    }
private:
    int backtrack(const string& s, int start, set<string>& st) {
        if (start == s.size()) return 0; 

        string x = "";
        int maxCount = 0;
        
        for (int i = start; i < s.size(); ++i) {
            x += s[i]; 
            if (st.find(x) == st.end()) {
                st.insert(x);
                
                maxCount = max(maxCount, 1 + backtrack(s, i + 1, st));
                
                st.erase(x);
            }
        }
        return maxCount;
    }
};