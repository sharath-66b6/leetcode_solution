class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int end = 0;
    int x = 0;

    for (int i = 0; i < nums.size()-1; ++i) {
      x = max(x, i + nums[i]);
      if (x >= nums.size() - 1) {
        ++ans;
        break;
      }
      if (i == end) {
        ++ans; 
        end = x;
      }
    }

    return ans;
  }
};
