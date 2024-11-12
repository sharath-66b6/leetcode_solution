class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,vector<int>& queries) {
        
        sort(items.begin(), items.end());

        int mb = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            mb = max(mb, items[i][1]);
            items[i][1] = mb;
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            ans[i] = binarysearch(items, queries[i]);
        }

        return ans;
    }
private:
    int binarysearch(vector<vector<int>>& items, int x) {
        int l = 0,r = items.size() - 1,mb = 0;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (items[mid][0] > x) {
                r = mid - 1;
            } else {
                mb = max(mb, items[mid][1]);
                l = mid + 1;
            }
        }
        return mb;
    }
};