class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto a:asteroids){
            if(a>0 || st.empty() || st.top()<0)
                st.push(a);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -a){
                    st.pop();
                }
                if(st.empty() || st.top()<0)
                    st.push(a);
                if(!st.empty() && st.top() == -a)
                    st.pop();
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};