class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n-k+1;i++){
            map<int, int> mp;
            for(int j=i;j<n && j<i+k;j++){
                mp[nums[j]]++;
            }

            vector<pair<int,int>> res(mp.begin(),mp.end());
            sort(res.begin(),res.end(), [](pair<int, int> a, pair<int, int> b){
                if(a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });

            int sum = 0;
            for(int j=0;j < res.size() && j<x; j++){
                sum += res[j].first * res[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};