class Solution {
public:
    int mod = 1000*1000*1000+7;
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0,j = 0, k = 0;
        vector<int> p(n);
        p[0]=nums[0];
        for(i=1;i<n;i++)
            p[i]=p[i-1]+nums[i];
        for (i = 0; i < n - 2; ++i){
            j = max(j, i + 1);
            while (j < n - 1 && p[i] > p[j] - p[i])
                ++j;
            k = max(k, j);
            while (k < n - 1 && p[k] - p[i] <= p[n-1] - p[k])
                ++k;
            ans += k - j;
            ans %= mod;
        }
        return ans;
    }
};