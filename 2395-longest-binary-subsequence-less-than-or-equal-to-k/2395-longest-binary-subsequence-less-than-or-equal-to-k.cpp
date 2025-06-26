class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int count = 0;
        long long num = 0;
        int power = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;
            } else {
                if (power < 31 && (num + (1LL << power)) <= k) {
                    num += (1LL << power);
                    count++;
                }
            }
            power++;
        }

        return count;
    }
};
