class Solution {
public:
    int minMaxDifference(int num) {
        string s,a,b;
        s = to_string(num);
        a = to_string(num);
        b = to_string(num);
        char x;
        for(auto &c:s){
            if(c != '9'){
                x = c;
                break;
            }
        }
        for(auto &c:a){
            if(c == x) c='9';
        }

        x=s[0];
        for(auto &c:b){
            if(c == x) c='0';
        }

        return stoi(a)-stoi(b);
    }
};