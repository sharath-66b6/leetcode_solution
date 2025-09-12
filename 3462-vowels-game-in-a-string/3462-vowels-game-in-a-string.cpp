class Solution {
private:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u'){
            return true;
        }
        return false;
    }
public:
    bool doesAliceWin(string s) {
        for(int c:s){
            if(isvowel(c))
                return true;
        }
        return false;
    }
};