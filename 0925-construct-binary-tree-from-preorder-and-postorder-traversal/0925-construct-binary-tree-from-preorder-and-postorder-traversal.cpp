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
    unordered_map<int, int> mp;
    int ind = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int left, int right){
        if(ind >= preorder.size() || left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[ind++]);

        if(left == right) return root;

        int postind = mp[preorder[ind]];

        root->left = construct(preorder, postorder, left, postind);
        root->right = construct(preorder, postorder, postind + 1, right - 1);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0; i<postorder.size(); i++){
            mp[postorder[i]] = i;
        }
        return construct(preorder, postorder, 0, postorder.size()-1);
        
    }
};