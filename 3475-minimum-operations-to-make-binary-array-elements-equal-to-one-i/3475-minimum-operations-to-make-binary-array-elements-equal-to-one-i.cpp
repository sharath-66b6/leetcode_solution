class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 2;
        int ans = 0;
        while(r<n){
            if(nums[l] == 0){
                for(int i=l;i<=r;i++)
                    nums[i] = (nums[i] == 0)? 1:0;
                ans++;
            }
            l++;
            r++;
        }
        for(int i=l;i<r;i++)
            if(nums[i] == 0)
                return -1;
        return ans;
    }
};