class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> v(n+2,1);
        for(auto i:banned){
            if(i<=n)
                v[i]=0;
        }
        int sum=0,c=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i])
            {
                sum+=i;
                if(sum > maxSum)
                    return c;
                c++;
            }
        }

        return c;
    }
};