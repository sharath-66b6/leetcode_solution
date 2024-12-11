class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int m=0 , r=0;
        sort(nums.begin(),nums.end());
        for(int l=0;l<nums.size();l++)
        {
            while(r < nums.size() && nums[r]-nums[l] <= 2*k)
                r++;
            
            m=max(m, r-l);
        }
        return m;

    }
};