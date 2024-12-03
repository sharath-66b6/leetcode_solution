class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str="";
        int c=0,j=0;
        for(int i=0;i<s.size();i++)
        {
            if (j < spaces.size() && c == spaces[j])
            {
                str+=" ";
                j++;
            }
            str+=s[i];
            c++;
        }
        return str;
    }
};