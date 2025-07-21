class Solution {
public:
    string makeFancyString(string s) {
        char last=NULL;
        int count=0;
        string ans="";
        for(auto c:s){
            if(c == last && count<2){
                count++;
                ans += c;
            }
            else if(c != last){
                last = c;
                count=1;
                ans += c;
            }
        }
        return ans;
    }
};