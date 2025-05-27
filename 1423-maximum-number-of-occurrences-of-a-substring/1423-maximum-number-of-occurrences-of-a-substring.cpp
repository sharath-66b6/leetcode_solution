class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans=0,i=0,j=0, un=0;
        map<char, int> count;
        map<string, int> substr;
        for(j=0;j<s.size();j++){
            count[s[j]]++;
            if(count[s[j]] == 1)
                un++;
            
            if(j-i+1 > minSize){
                count[s[i]]--;
                if(count[s[i]] == 0)
                    un--;
                i++;
            }

            if(j-i+1 == minSize && un <= maxLetters){
                string str = s.substr(i, minSize);
                substr[str]++;
                ans = max(ans, substr[str]);
            }
        }
        return ans;
    }
};