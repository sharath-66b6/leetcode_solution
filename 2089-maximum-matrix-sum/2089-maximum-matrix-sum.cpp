class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),count=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] < 0)
                    count++;
                sum+=abs(matrix[i][j]);
            }
        }
        if(count%2 == 0)
            return sum;
        int abs_mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                abs_mn=min(abs_mn,abs(matrix[i][j]));
            }
        }

        return sum-(2*abs_mn);
    }
};