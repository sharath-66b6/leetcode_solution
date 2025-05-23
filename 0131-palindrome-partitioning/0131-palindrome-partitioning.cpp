class Solution {
public:
    vector<vector<string>> res;
    bool p(string s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void func(string s, int ind, vector<string>& v){
        if(ind == s.size()){
            res.push_back(v);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(p(s,ind,i)){
                v.push_back(s.substr(ind, i-ind+1));
                func(s, i+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        func(s, 0, v);
        return res;
    }
};