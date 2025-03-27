class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp2,mp1;
        for(int i=0;i<n;i++){
            mp2[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            mp2[nums[i]]--;
            mp1[nums[i]]++;
            if(mp1[nums[i]]*2 > (i+1) && mp2[nums[i]]*2 > (n-i-1))
                return i;
        }
        return -1;
    }
};