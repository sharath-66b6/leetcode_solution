class Solution {
public:
    long long coloredCells(int n) {
        unsigned long long x = n;
        return 1 + 2 * (x-1) * (x);
    }
};