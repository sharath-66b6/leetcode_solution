class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<int> p(n,1);
        for(int i=1;i<n;i++){
            p[i] = p[i-1]*2 % mod;
        }
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int l=0, r=n-1; l<=r;){
            if(nums[l]+nums[r] <= target){
                ans += p[r-l];
                ans %= mod;
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};