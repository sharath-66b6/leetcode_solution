class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i=0;i<nums1.size();i++){
            int num = nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j] == num){
                    nums1[i] = j;
                    break;
                }
            }
        }

        int n2 = nums2.size();
        vector<int> res(n2, -1);
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto x:nums1){
            ans.push_back(res[x]);
        }

        return ans;
    }
};