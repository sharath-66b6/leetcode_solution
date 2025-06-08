class Node{
public: 
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};
class Solution {
public:
    Node* root = new Node();
    vector<int> dp;
    void solve(int n,int val, Node* node){
        if(val > n)
            return;
        dp.push_back(val);
        node->value = val;
        
        int l = val*10;
        if(node->left == nullptr)
            node->left = new Node();
        solve(n, l, node->left);

        int r = val+1;
        if(r%10 == 0) return;
        if(node->right == nullptr)
            node->right = new Node();
        solve(n, r, node->right);
    }
    vector<int> lexicalOrder(int n) {
        solve(n, 1, root);
        return dp;
    }
};