class Solution {
public:
    string compressedString(string word) {
        word+=" ";
        int c=1;
        string s="";
        for(int i=0;i<word.size()-1;i++)
        {
            if(word[i] != word[i+1] || c>=9){
                s+=(to_string(c)+word[i]);
                c=(c>=9) ? c%9+1:1;
            }
            else if(word[i] == word[i+1])
                c++;

        }
        return s;
    }
};