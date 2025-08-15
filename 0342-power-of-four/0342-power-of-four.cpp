class Solution {
public:
    bool isPowerOfFour(int n) {
        double x = log(n) / log(4);
        return n>0 && (x == int(x));
    }
};