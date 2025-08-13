class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n != 0 && n%3 == 0){
            // int num = 0;
            // while(n<0){
            //     int rem = n%10;
            //     n /= 10;
            //     num += rem;
            // }
            n = n/3;
        }
        return n == 1;
    }
};