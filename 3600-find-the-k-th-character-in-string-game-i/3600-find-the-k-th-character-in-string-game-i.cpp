class Solution {
public:
    char kthCharacter(int k) {
        string a="a";
        string b="";
        while(a.size() < k){
            for(auto c:a){
                b += c+1;
            }
            a += b;
            b = "";
        }
        return a[k-1];
    }
};