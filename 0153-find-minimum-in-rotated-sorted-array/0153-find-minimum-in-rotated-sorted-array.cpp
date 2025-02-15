class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = 1, n = nums.size()-1;
        while(n--){
            if(nums[l]>nums[r])
                l=r;
            r++;
        }
        return nums[l];
    }
};