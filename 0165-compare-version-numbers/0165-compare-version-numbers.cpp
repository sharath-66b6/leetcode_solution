class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        stringstream ss1(version1);
        string s1;
        while(getline(ss1,s1,'.')){
            v1.push_back(stoi(s1));
            cout<<v1.back()<<" - ";
        }
        cout<<"\n";
        stringstream ss2(version2);
        string s2;
        while(getline(ss2,s2,'.')){
            v2.push_back(stoi(s2));
            cout<<v2.back()<<" - ";
        }

        while(v1.size() < v2.size()){
            v1.push_back(0);
        }
        while(v1.size() > v2.size()){
            v2.push_back(0);
        }

        for(int i=0;i<v1.size();i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};