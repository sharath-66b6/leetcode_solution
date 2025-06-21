class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(auto c:word)
            freq[c-'a']++;

        int ans=INT_MAX;
        for(int i:freq){
            int d=0;
            for(int j:freq){
                if(j<i)
                    d += j;
                else
                    d += max(0,j-(i+k));
            }
            ans = min(ans, d);
        }
        return ans;
    }
};