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
    Node* clone(Node* node, unordered_map<Node*, Node*>& mp){
        if(node == nullptr) return nullptr;

        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto n:node->neighbors){
            if(mp[n]){
                (newNode->neighbors).push_back(mp[n]);
            }
            else{
                (newNode->neighbors).push_back(clone(n, mp));
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return clone(node, mp);
    }
};