class Solution {
public:
    int maxFreqSum(string s) {
        vector<char> v = {'a', 'e', 'i', 'o','u'};
        int mxv=0 , mxc=0;
        map<char, int> mp;
        for(auto c:s) mp[c]++;
        for(auto [c,freq]:mp){
            if(find(v.begin(), v.end(), c) != v.end())
                mxv = max(mxv, freq);
            else
                mxc = max(mxc, freq);
        }
        return mxv+mxc;
    }
};