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
class FindElements {
public:
    vector<int> v;
    FindElements(TreeNode* root) {
        if(root->val == -1){
            root->val = 0;
            v.push_back(root->val);
        }

        set(root);
        return;
    }
    void set(TreeNode* root){
        int x = root->val;
        if(root->left != nullptr){
            TreeNode* l = root->left;
            l->val = 2*x + 1;
            v.push_back(l->val);
            set(l);
        }
        if(root->right != nullptr){
            TreeNode* r = root->right;
            r->val = 2*x + 2;
            v.push_back(r->val);
            set(r);
        }
        return;
    }
    
    bool find(int target) {
        return (std::find(v.begin(),v.end(),target) != v.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */