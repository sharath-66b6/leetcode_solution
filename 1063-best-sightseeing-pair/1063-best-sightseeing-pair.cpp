class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int mx = values[0];
        int m=0;
        for(int i=1;i<n;i++)
        {
            int currj = values[i]-i;
            m = max(m, currj + mx);

            int curri = values[i]+i;  
            mx = max(mx, curri);
        }

        return m;
    }
};