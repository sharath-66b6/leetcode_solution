class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int mx = 0, c = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                c++;
            }
            else{
                c = 1;
            }
            mx = max(c, mx);
        }
        return mx;
    }
};