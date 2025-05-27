class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ind = -1, ans = 1, i=0;
        for(int j=1;j<s.size();j++){
            if(s[j-1] == s[j]){
                if(ind != -1)
                    i = ind+1;
                ind = j-1;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};