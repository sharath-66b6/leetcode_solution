class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<int, int> mp;
        for(char c:brokenLetters){
            mp[c]++;
        }
        int ans = 0;
        stringstream ss(text);
        string s;
        while(ss>>s){
            ans++;
            for(auto c:s){
                if(mp[c]){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};