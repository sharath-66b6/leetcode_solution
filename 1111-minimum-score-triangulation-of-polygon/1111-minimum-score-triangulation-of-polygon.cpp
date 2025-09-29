class Solution {
private:
    unordered_map<int, int> dp;
    int solve(int i, int j, vector<int>& values){
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }
        int n = values.size();
        int key = i * n + j;
        if (!dp.count(key)) {
            int minScore = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                minScore = min(minScore, values[i] * values[k] * values[j] +
                                                solve(i, k, values) + solve(k, j, values));
            }
            dp[key] = minScore;
        }
        return dp[key];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
    //     int ans = 0;
    //     for(int i=2;i<n;i++){
    //         ans += values[0]*values[1]*values[i];
    //     }
        return solve(0,n-1,values);
    }
};