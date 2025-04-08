class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int operations = 0;
        while (true) {
            std::unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            if (freq.size() == nums.size()) {
                break;
            }
            nums.erase(nums.begin(), nums.begin() + std::min(3, (int)nums.size()));
            operations++;
        }
        return operations;
    }
};