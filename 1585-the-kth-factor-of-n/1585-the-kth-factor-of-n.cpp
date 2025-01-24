class Solution {
public:
    int kthFactor(int n, int k) {
        
        vector<int> ans={1,n};

        for(int i=2;i<=n/2;i++)
        {
            if(n%i == 0)
                ans.push_back(i);
        }
        if(ans.size() < k)
            return -1;
    
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};