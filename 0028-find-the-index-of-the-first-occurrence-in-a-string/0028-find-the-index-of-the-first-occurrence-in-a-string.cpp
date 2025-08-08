class Solution {
public:
    int strStr(string a, string b) {
        int i,j;
        for(i=0,j=0;j<b.size() && i<a.size();i++){
            if(a[i] == b[j]){
                j++;
            }
            else{
                i = i-j;
                j=0;
            }
        }
        if(j == b.size()){
            return i-j;
        }
        else{
            return -1;
        }
    }
};