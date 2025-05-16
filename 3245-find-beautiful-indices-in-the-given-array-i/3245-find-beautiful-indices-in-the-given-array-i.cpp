class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int sl=s.size(), al=a.size(), bl=b.size();
        vector<int> y,x,ans;
        for(int i=0;i <= sl - al; i++){
            if(s.substr(i,al) == a){
                x.push_back(i);
                cout<<i<<" ";
            }
        }
        for(int i=0;i <= sl - bl; i++){
            if(s.substr(i,bl) == b){
                y.push_back(i);
                cout<<i<<" ";
            }
        }
        int i=0,j=0;
        while(i<x.size() && j<y.size()){
            int dif = abs(x[i]-y[j]);
            if(dif <= k){
                ans.push_back(x[i]);
                i++;
            }
            else{
                if(x[i] < y[j])
                    i++;
                else
                    j++;
            }
        }
        return ans;
    }
};