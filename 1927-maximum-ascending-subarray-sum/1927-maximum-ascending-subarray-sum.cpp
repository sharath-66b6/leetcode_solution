class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = nums[0], sum = nums[0];

        int i=0,j=1;
        while(j<nums.size()){
            if(nums[j-1] < nums[j]){
                sum += nums[j];
            }
            else{
                i=j;
                sum = nums[j];
            }
            j++;
            mx = max(mx, sum);
        }
        return mx;
    }
};