class Node {
public:
    vector<Node*> next;
    bool isEnd;

    Node() : next(26, nullptr), isEnd(false) {}
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (auto c : word) {
            int n = c - 'a';
            if (node->next[n] == nullptr) {
                node->next[n] = new Node();
            }
            node = node->next[n];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;
        for (auto c : word) {
            int n = c - 'a';
            if (node->next[n] == nullptr)
                return false;
            node = node->next[n];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (auto c : prefix) {
            int n = c - 'a';
            if (node->next[n] == nullptr)
                return false;
            node = node->next[n];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */