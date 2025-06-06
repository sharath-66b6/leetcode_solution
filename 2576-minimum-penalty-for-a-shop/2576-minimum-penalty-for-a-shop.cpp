class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0;
        int profit = 0;
        int mxp = 0;

        for (int i = 0; i < customers.length(); ++i) {
            profit += customers[i] == 'Y' ? 1 : -1;
            if (profit > mxp) {
                mxp = profit;
                ans = i + 1;
            }
        }

        return ans;
        }
};