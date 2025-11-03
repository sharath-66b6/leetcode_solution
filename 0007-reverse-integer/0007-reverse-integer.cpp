class Solution {
public:
    int reverse(int x) {
        long long n=0;
        while(x!=0){
            int rem = x % 10;
            n = n*10 + rem;
            x /= 10;
        }

        if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min()) {
                return 0;
            }

        return n;
    }
};