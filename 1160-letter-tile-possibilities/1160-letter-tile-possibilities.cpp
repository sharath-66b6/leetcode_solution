class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for(auto c:tiles)
            freq[c]++;
        
        int count = 0;
        backtrack(freq, count);
        return count;
    }

    void backtrack(unordered_map<char, int>& freq, int& count){
        for(auto& [c,f]:freq){
            if(f>0){
                count++;
                freq[c]--;
                backtrack(freq,count);
                freq[c]++;
            }
        }
    }
};