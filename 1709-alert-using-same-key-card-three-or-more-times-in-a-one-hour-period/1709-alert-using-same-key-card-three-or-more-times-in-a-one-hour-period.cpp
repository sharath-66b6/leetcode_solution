class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        map<string , vector<int>> mp;
        for(int i=0; i<n; i++){
            int time = stoi(keyTime[i].substr(0,2))*60;
            time += stoi(keyTime[i].substr(3,2));
            mp[keyName[i]].push_back(time);
        }
        vector<string> ans;
        for(auto& [name, v]:mp){
            
            // sort(v.begin(),v.end());
            if(v.size() < 3) continue;
            ranges::sort(v);
            // cout<<name<<"\n";
            for(int i=0,j=2;j<v.size();i++,j++){
                // cout<<name<<" "<<v[i]<<" "<<v[j]<<"\n";
                if(v[j]-v[i] <=60){
                    ans.push_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};