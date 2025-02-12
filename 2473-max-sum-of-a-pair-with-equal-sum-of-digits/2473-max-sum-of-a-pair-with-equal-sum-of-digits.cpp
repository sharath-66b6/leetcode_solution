class Solution {
public:
    int sumof(int n){
        int x=0;
        while(n!=0){
            x += (n%10);
            n /= 10;
        }
        return x;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> m;
        for(auto n:nums){
            m[sumof(n)].push_back(n);
        }

        int mx = -1;
        for(auto [x,y]:m){

            if(y.size() >= 2){
                int m1 = INT_MIN, m2 = INT_MIN;
                for(auto i:y){
                    if(m1 <= i){ 
                        m2 = m1;
                        m1 = i;
                    }
                    else if(m2 <= i){
                        m2 = i;
                    }

                }
                mx = max(mx, m1+m2);
            }
        }
        return mx;
    }
};