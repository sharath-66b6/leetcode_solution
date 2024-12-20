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
    void traverse(TreeNode* lc, TreeNode* rc, int level)
    {
        if(lc == NULL || rc == NULL)
            return;
        
        if(level % 2 == 0)
        {
            int t = lc->val;
            lc->val = rc->val;
            rc->val = t;
        }

        traverse(lc->left, rc->right, level + 1);
        traverse(lc->right, rc->left, level + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(root->left, root->right, 0);
        return root;
    }
};