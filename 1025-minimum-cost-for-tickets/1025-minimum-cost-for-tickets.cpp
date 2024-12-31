class Solution {
public:
    vector<int> d ;
    vector<int> dp;
    map<int,int> costMap;
    
    Solution() : dp(365, INT_MAX) {}

    int solve(int i)
    {
        if(i >= d.size())
            return 0;
        
        if(dp[i] != INT_MAX)
            return dp[i];
        
        int j = i;
        for (const auto& [duration, cost] : costMap) {
            while (j < d.size() && d[j] < d[i] + duration) {
                j++;
            }
            dp[i] = min(dp[i], solve(j) + cost);
        }
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        d = days;
        costMap[1]=costs[0];
        costMap[7]=costs[1];
        costMap[30]=costs[2];

        return solve(0);
    }
};