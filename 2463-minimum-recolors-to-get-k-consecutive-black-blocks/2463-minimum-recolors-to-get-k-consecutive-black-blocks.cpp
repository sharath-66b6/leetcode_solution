class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mn = 0;
        int i=0, j=0, n = blocks.size();
        for(;j<k;j++){
            if(blocks[j] == 'W')
                mn++;
        }
        int m = mn;
        while(j<n){
            if(blocks[i] == 'W' && blocks[j] != 'W'){
                m--;
            }
            else if(blocks[i] != 'W' && blocks[j] == 'W'){
                m++;
            }
            i++;
            j++;
            if(m == -1) cout<<i<<j;
            mn = min(mn, m);
        }
        return mn;
    }
};