class LRUCache {
private:
    class node {
      public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    int n;
    unordered_map<int, node*> mp;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    void insertNode(node* curr){
        node* fristnode = head->next;
        
        curr->next = fristnode;
        curr->prev = head;
        head->next = curr;
        fristnode->prev = curr;
    }

    void deleteNode(node* curr){
        node* prevNode = curr->prev;
        node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity){
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int k) {
        if (mp.find(k) != mp.end()) {
            node* curr = mp[k];
            int v = curr->val;

            mp.erase(k);
            deleteNode(curr);
            insertNode(curr);
            mp[k] = head->next;

            return v;
        }
        return -1;
    }
    
    void put(int k, int v) {
        if (mp.find(k) != mp.end()) {
            node* curr = mp[k];
            mp.erase(k);
            deleteNode(curr);
        } 
        if (mp.size() >= n) {
            node* lastNode = tail->prev;
            mp.erase(lastNode->key);
            deleteNode(lastNode);
        }
        
        node* curr = new node(k, v);
        insertNode(curr);
        mp[k] = head->next;
    }
};
