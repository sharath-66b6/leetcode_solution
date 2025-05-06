class Solution {
public:
    string largestMultipleOfThree(vector<int>& d) {
        vector<int>a,b,c;
        int s=0;
        for(int i=0;i<d.size();i++){
            s+=d[i];
            if(d[i]%3==0)a.push_back(d[i]);
            else if(d[i]%3==1)b.push_back(d[i]);
            else c.push_back(d[i]);
        }
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        if(s%3==1){
            if(b.size()>0)b.erase(b.begin());
            else if(c.size()>1)c.erase(c.begin(),c.begin()+2);
            else return "";
        }else if(s%3==2){
            if(c.size()>0)c.erase(c.begin());
            else if(b.size()>1)b.erase(b.begin(),b.begin()+2);
            else return "";
        }
        vector<int>x;
        for(int i=0;i<a.size();i++)x.push_back(a[i]);
        for(int i=0;i<b.size();i++)x.push_back(b[i]);
        for(int i=0;i<c.size();i++)x.push_back(c[i]);
        if(x.size()==0)return "";
        sort(x.begin(),x.end(),greater<int>());
        if(x[0]==0)return "0";
        string res="";
        for(int i=0;i<x.size();i++)res+=to_string(x[i]);
        return res;
    }
};
