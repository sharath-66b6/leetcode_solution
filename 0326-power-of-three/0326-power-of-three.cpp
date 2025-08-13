class Solution {
public:
    bool isPowerOfThree(int n) {

        int mx = pow(3,19);
        return n>0 && mx%n == 0;
    }
};