class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        int i=0,j=0;
        long long c=0;
        while(j<n)
        {
            m[nums[j]]++;
            while( (m.rbegin()->first - m.begin()->first) >2)
            {
                m[nums[i]]--;
                if(m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            c += (j-i+1);
            j++;
        }
        return c;
    }
};