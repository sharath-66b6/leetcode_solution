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
    vector<int> res;
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int level = q.size();
            int mx = INT_MIN;
            while(level--){
                TreeNode* curr = q.front();
                q.pop();

                mx = max(mx, curr->val);
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};