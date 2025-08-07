class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = -1e9;
        int pref=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                pref = 1;
                mx = max(mx, 0);
            }
            else{
                pref *= nums[i];
                mx = max(mx, pref);
            }
        }
        int suf=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == 0){
                suf = 1;
                mx = max(mx, 0);
            }
            else{
                suf *= nums[i];
                mx = max(mx, suf);
            }
        }
        return mx;
    }
};