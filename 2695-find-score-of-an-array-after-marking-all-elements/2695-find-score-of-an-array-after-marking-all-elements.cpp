class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        long long sum=0;
        
        sort(v.begin(), v.end());
        vector<bool> marked(nums.size(), false);
        for(auto i = 0; i < nums.size(); i++)
        {
            int idx = v[i].second;
            if(!marked[idx]){
                marked[idx]=true;
                if(idx-1 >=0){
                    marked[idx-1] = true;
                }
                if(idx+1 < nums.size() &&  nums[idx+1] != -1){
                    marked[idx+1] = true;
                }
                sum += v[i].first;
            }
        }
        return sum;
    }
};