class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l<r)
        {
            int m = l+(r-l)/2;
            int count=0;

            for (int num : nums) {
                count += (num + m - 1) / m - 1;
                if (count > maxOperations) break;
            }
            
            if(count <= maxOperations)
            {
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};
