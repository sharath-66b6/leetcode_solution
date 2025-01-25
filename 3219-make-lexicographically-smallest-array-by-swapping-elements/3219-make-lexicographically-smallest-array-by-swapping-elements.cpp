class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());

        vector<deque<int>> group(1);
        map<int,int> mp;
        int idx = 0;

        group[idx].push_back(sorted[0]);
        mp[sorted[0]] = idx;
        for(int i=1;i<sorted.size();i++)
        {
            if(abs(sorted[i] - sorted[i-1]) > limit){
                idx++;
                group.push_back(deque<int> ());
            }
            group[idx].push_back(sorted[i]);
            mp[sorted[i]] = idx;
        }

        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int j = mp[nums[i]];
            ans.push_back(group[j].front());
            group[j].pop_front();
        }
        return ans;
    }
};