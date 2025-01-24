class Solution {
public:
    int partitionString(string s) {
        set<int> st;
        int mx = 1;
        for(char c:s){
            
            if(st.find(c) != st.end()){
                mx++;
                st.clear();
            }
            st.insert(c);
        }
        return mx;
    }
};