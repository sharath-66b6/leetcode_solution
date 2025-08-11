class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int mxbit = 30;
        vector<int> ans;
        vector<int> pows;

        for (int i = 0; i < mxbit; ++i)
            if (n >> i & 1)
                pows.push_back(1 << i);

        for (vector<int>& query : queries) {
            int left = query[0];
            int right = query[1];
            long prod = 1;
            for (int i = left; i <= right; ++i) {
                prod *= pows[i];
                prod %= mod;
            }
            ans.push_back(prod);
        }

        return ans;
    }
};
