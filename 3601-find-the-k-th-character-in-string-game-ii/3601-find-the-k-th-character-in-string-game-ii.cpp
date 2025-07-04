class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int c = ceil(log2(k));
        int inc = 0;

        for (int i = c - 1; i >= 0; --i) {
            long x = 1L << i;
            if (k > x) {
                k -= x;
                inc += operations[i];
            }
        }

        return 'a' + inc % 26;
    }
};