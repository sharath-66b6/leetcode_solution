class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, mx = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            
            mx = max(mx, right - left + 1);
        }
        
        return mx - 1;
    }
};
