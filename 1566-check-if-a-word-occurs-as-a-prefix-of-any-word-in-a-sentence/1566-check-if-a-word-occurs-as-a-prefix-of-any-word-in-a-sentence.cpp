class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> words;
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }

        int n=searchWord.size();
        for(int i=0;i<words.size();i++)
        {
            if(words[i].substr(0,n) == searchWord)
                return i+1;
        }
        return -1;
    }
};