class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> map;


        for(int i=0;i<matrix.size();i++)
        {
            string key="";
            if(matrix[i][0] == 0){
                for(int j=0;j<matrix[0].size();j++)
                {
                    key+=to_string(matrix[i][j]);
                }
                map[key]++;
            }
            else
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    key+=to_string(!matrix[i][j]);
                }
                map[key]++;
            }
        }

        int m = 0;
        for (const auto& [key, count] : map) {
            m = max(m, count);
        }

        return m;
    }
};