class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        n--;
        int i = -n;
        while(i<=n){
            v.push_back(i);
            i+=2;
        }
        return v;
    }
};