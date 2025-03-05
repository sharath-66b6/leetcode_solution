class Solution {
public:
    long long coloredCells(int n) {
        long long x=4,res=1;
        n--;
        while(n--){
            res += x;
            x += 4;
        }
        return res;
    }
};