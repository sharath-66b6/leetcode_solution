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
    TreeNode* build(int& idx, int l, int r,vector<int>& preorder, unordered_map<int, int>& inord_pos){
        if(l > r) return nullptr;
        int mid = inord_pos[preorder[idx]];
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = build(idx, l, mid-1, preorder, inord_pos);
        node->right = build(idx, mid+1, r, preorder, inord_pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inord_pos;
        for(int i=0;i<n;i++){
            inord_pos[inorder[i]] = i;
        }
        int idx = 0;
        return build(idx, 0, n-1, preorder, inord_pos);
    }
};