class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        

        int n2 = nums2.size();
        unordered_map<int, int> res;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            res[nums2[i]] = st.empty()? -1:st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto x:nums1){
            ans.push_back(res[x]);
        }

        return ans;
    }
};