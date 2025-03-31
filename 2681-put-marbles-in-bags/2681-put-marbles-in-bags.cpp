class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n < 2 || k <= 0) return 0;
        long long mx = 0, mn = 0;

        vector<long long> s;
        for(int i=0;i<n-1;i++){
            s.push_back(weights[i]+weights[i+1]);
        }

        sort(s.begin(), s.end());
        int len = s.size();

        int limit = min(k - 1, len);
        for (int i = 0; i < limit; i++) {
            mn += s[i];
            mx += s[len - i - 1];
        }

        return mx-mn;
    }
};