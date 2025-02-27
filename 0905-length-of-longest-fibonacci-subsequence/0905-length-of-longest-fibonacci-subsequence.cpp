class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int> (n,2));
        int mx = 0;
        for(int j=0;j<n;j++){
            for(int k = j + 1; k < n; ++k){
                int nxt = a[k] - a[j];
                if (nxt < a[j] && mp.contains(nxt)) {
                    const int i = mp[nxt];
                    dp[j][k] = dp[i][j] + 1;
                    mx = max(mx, dp[j][k]);
                }
            }
        }
        return mx;
    }
};