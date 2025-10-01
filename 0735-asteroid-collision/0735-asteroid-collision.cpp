class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        int i=0;
        while(i<n){
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                int t = st.top(); st.pop();
                if(abs(t) > abs(asteroids[i])){
                    asteroids[i] = t;
                }
                else if(abs(t) == abs(asteroids[i])){
                    i++;
                }
            }
            else{
                st.push(asteroids[i]);
                i++;
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