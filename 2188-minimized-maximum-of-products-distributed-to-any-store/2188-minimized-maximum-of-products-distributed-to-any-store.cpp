class Solution {
public:
    bool can(int x, vector<int>& quantities,int n)
    {
        int j=0;
        int remaining = quantities[j];
        for (int i = 0; i < n; i++) {
            if (remaining <= x) {
                
                j++;
                if (j == quantities.size()) {
                    return true;
                } else {
                    remaining = quantities[j];
                }
            } else {
                remaining -= x;
            }
        }
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,r=*max_element(quantities.begin(),quantities.end());
        int res=0,count=0;
        while(l < r){
            int x=(l+r)/2;
            
            if(can(x,quantities,n)){
                r = x;
            }
            else{
                l=x+1;
            }
        }
        return l;
    }
};