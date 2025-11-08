class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int t = q.front().second;
            q.pop();
            if(word == endWord) return t;
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,t+1});
                    }
                    
                }
                word[i] = org;
            }
        }
        return 0;
    }
};