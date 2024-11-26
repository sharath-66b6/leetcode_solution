class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n,0);

        for(auto x:edges){
            v[x[1]]++;
        }
        int winner=-1,count=0;
        for(int i=0;i<n;i++)
        {
            if(v[i] == 0)
            {
                count++;
                winner=i;
            }
        }

        return count>1 ? -1 : winner;
    }
};