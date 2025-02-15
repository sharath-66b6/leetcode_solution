class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    const int lcount = countNodes(root->left);

    if(lcount == k-1)
        return root->val;
    else if(lcount >= k)
        return kthSmallest(root->left, k);
    return kthSmallest(root->right, k-1-lcount);
  }

 private:
  int countNodes(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
