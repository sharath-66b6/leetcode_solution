class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int in = 1, dec = 1, mx = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                in++;
                dec=1;
            }
            else if(nums[i-1] > nums[i]){
                in=1;
                dec++;
            }
            else{
                in=1;
                dec=1;
            }
            mx = max(mx, max(in, dec));
        }

        return mx;
    }
};