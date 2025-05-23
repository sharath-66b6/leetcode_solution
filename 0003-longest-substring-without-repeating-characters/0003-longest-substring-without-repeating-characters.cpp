class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, mx = 0;
        unordered_map<char, int> m;
        while(j<s.size()){
            m[s[j]]++;
            while(m[s[j]] > 1){
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};