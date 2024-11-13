class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return find_bound(nums, upper + 1) - find_bound(nums, lower);
    }

private:
    long long find_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long count = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < value) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};
