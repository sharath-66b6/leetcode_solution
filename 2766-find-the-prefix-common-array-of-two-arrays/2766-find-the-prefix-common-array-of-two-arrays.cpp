class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c(A.size()+1,1), ans(A.size());
        
        for(int i=A.size()-1;i>=0;i--)
        {
            ans[i] = count(c.begin(), c.end(), 1)-1;

            c[A[i]]=0;
            c[B[i]]=0;
        }
        return ans;
    }
};