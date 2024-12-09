class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,int>> party(nums.size());
        party[0]={nums[0]%2,0};
        int c=0;
        for(int i=1;i<nums.size();i++)
        {
            int x = nums[i]%2;
            if(party[i-1].first == x)
                c=i;
            party[i]={x,c};
        }

        vector<bool> ans;
        for(auto query:queries)
        {
            
            if(query[0] == query[1]){
                ans.push_back(true);
                continue;
            }
            if(query[0] >= party[query[1]].second)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};