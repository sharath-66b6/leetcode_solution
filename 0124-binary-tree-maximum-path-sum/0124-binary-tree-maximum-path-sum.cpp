/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxpath(TreeNode* root,int& mx){
        if(!root) return 0;
        int lsum = maxpath(root->left, mx);
        int rsum = maxpath(root->right, mx);
        int sum = root->val + max(lsum, rsum);
        mx = max({mx, root->val + lsum + rsum});
        return max(0,sum);
    }
    int maxPathSum(TreeNode* root) {
        int mx = -1001;
        maxpath(root, mx);
        return mx;
    }
};