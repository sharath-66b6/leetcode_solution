class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream stream(sentence);
        vector<string> words;
        string word;

        while (stream >> word) {
            words.push_back(word);
        }
        int n=words.size();
        char l=words[n-1].back();
        for(int i=0;i<n;i++)
        {
            if(words[i].front() != l)
                return false;
            l=words[i].back();
        }
        return true;
    }
};