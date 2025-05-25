/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        auto it = mp.find(node);
        if(it != mp.cend())
            return it->second;
        
        Node* n = new Node(node->val);
        mp[node] = n;

        for(auto ni : node->neighbors){
            n->neighbors.push_back(cloneGraph(ni));
        }
        return n;
    }
};