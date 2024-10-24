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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return 0;

        vector<int> levelsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            int currlevelsum=0;
            while(levelsize--)
            {
                TreeNode* node=q.front();
                q.pop();

                currlevelsum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelsum.push_back(currlevelsum);
        }

        q.push(root);
        int levelindex=1;
        root->val=0;

        while(!q.empty()){
            int levelsize=q.size();
            while(levelsize--)
            {
                TreeNode* node=q.front();
                q.pop();
                int sibsum=(node->left? node->left->val:0)+(node->right? node->right->val:0);

                if(node->left){
                    node->left->val=levelsum[levelindex]-sibsum;
                    q.push(node->left);
                }
                if(node->right)
                {
                    node->right->val=levelsum[levelindex]-sibsum;
                    q.push(node->right);
                }

            }
            levelindex++;
        }
        return root;
    }
};