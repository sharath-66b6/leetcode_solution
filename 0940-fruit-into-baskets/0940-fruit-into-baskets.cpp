class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,mx=0;
        map<int, int> mp;
        for(int j=0;j<fruits.size();j++){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};