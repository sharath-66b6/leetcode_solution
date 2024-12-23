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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }


    int minimumOperations(TreeNode* root) {
        vector<vector<int>> nodes = levelOrder(root);
        

        int res=0;
        for(int i=1;i<nodes.size();i++)
        {
            vector<int> l=nodes[i], sl=nodes[i];
            sort(sl.begin(),sl.end());

            map<int,int> m;
            for(int j=0;j<l.size();j++)
                m[l[j]] = j;
            
            for(int j=0;j<l.size();j++)
            {
                if(l[j] != sl[j])
                {
                    res++;

                    int idx = m[sl[j]];
                    l[idx] = l[j];
                    m[l[j]] = idx;
                }
            }
        }
        return res;
    }
};