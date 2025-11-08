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
class BSTIterator{
    stack<TreeNode*> st;
    bool forward;
public:
    BSTIterator(TreeNode* root, bool forward): forward(forward){
        pushAll(root);
    }
    bool hasNext(){
        return st.size();
    }
    int next(){
        
        TreeNode* next = st.top();
        st.pop();
        if(forward)
            pushAll(next->right);
        else
            pushAll(next->left);
        return next->val;
    
    }
private:
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(forward)
                root = root->left;
            else
                root = root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, true);
        BSTIterator r(root, false);
        
        int i = l.next();
        int j = r.next();

        while(i<j){
            int sum = i + j;
            if(sum == k)
                return true;
            else if(sum < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};





// class Solution {
// private:
//     bool find(TreeNode* root, int a, int b){
//         if(!root) return false;

//         if(root->val != a && root->val == b){
//             return true;
//         }

//         bool l = find(root->left, a, b);
//         bool r = find(root->right, a, b);
//         return l ? l:r;
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(!root) return false;

//         TreeNode* dummy = root;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int n = q.size();
//             while(n--){
//                 TreeNode* node = q.front();
//                 q.pop();

//                 int rem = k - node->val;
//                 if(find(dummy, node->val, rem)) return true;

//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//         }   
//         return false;     
//     }
// };