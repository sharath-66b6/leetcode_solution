class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }


        int len=0,end=0;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            len++;
            end = max(end, mp[s[i]]);
            if(i == end){
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};