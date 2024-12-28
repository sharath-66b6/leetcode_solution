class Solution {
public:
    vector<int> k_sums;
    vector<vector<int>> dp;
    int n, k;

    int getMaxSum(int i, int cnt) {
        if (cnt == 3 || i > n - k) return 0;
        if (dp[i][cnt] != -1) return dp[i][cnt];
        int include = k_sums[i] + getMaxSum(i + k, cnt + 1);
        int skip = getMaxSum(i + 1, cnt);
        return dp[i][cnt] = max(include, skip);
    }

    vector<int> getIndices() {
        vector<int> indices;
        int i = 0;
        while (i <= n - k && indices.size() < 3) {
            int include = k_sums[i] + (i + k <= n - k ? getMaxSum(i + k, indices.size() + 1) : 0);
            int skip = (i + 1 <= n - k ? getMaxSum(i + 1, indices.size()) : 0);
            if (include >= skip) {
                indices.push_back(i);
                i += k;
            } else {
                i++;
            }
        }
        return indices;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this->k = k;
        n = nums.size();
        k_sums.resize(n - k + 1, 0);
        dp.assign(n, vector<int>(4, -1));

        int curr_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_sum += nums[i];
        }
        k_sums[0] = curr_sum;
        for (int i = 1; i <= n - k; i++) {
            curr_sum += nums[i + k - 1] - nums[i - 1];
            k_sums[i] = curr_sum;
        }

        getMaxSum(0, 0);
        return getIndices();
    }
};
