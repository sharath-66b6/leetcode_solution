class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=1, c=0;
        int num = *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num){
                c++;
            }else{
                c=0;
            }
            mx = max(mx, c);
        }
        return mx;
    }
};