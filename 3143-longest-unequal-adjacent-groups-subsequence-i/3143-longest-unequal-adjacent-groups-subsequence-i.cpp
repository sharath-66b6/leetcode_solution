class Solution {
public:
    map<pair<int, int>, vector<string>> dp;

    vector<string> solve(int i, int prevGroup, vector<string>& words, vector<int>& groups) {
        if (i == words.size()) return {};

        auto key = make_pair(i, prevGroup);
        if (dp.find(key) != dp.end()) return dp[key];

        vector<string> skip = solve(i + 1, prevGroup, words, groups);

        vector<string> take;
        if (groups[i] != prevGroup) {
            take = solve(i + 1, groups[i], words, groups);
            take.insert(take.begin(), words[i]);
        }

        if (take.size() > skip.size())
            return dp[key] = take;
        else
            return dp[key] = skip;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        return solve(0, -1, words, groups);
    }
};