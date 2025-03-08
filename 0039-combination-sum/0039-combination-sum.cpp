class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int> arr, int i,int t, vector<int>& ds){
        if(i == n || t < 0) return;
        if(t == 0){
            ans.push_back(ds);
            return;
        }

        if(arr[i] <= t){
            ds.push_back(arr[i]);
            solve(arr, i, t-arr[i], ds);

            ds.pop_back();
        }
        solve(arr, i+1, t, ds);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        n = candidates.size();
        vector<int> ds;
        
        solve(candidates, 0, target, ds);

        return ans;
    }
};