class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = size(nums), mx = 0;
        if(nums[0] == 0) return n == 1;
        for(int i=0;i<=mx;i++)
        {
            if(mx >= n-1) return true;
            mx = max(mx, i+nums[i]);
        }
        return false;
    }
};