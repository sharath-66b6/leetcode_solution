class LRUCache {
private:
    int n;
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> key_pos;
    list<int> keys;

public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int k) {
        if (mp.find(k) != mp.end()) {
            keys.erase(key_pos[k]);
            keys.push_front(k);
            key_pos[k] = keys.begin();
            return mp[k];
        }
        return -1;
    }
    
    void put(int k, int v) {
        if (mp.find(k) != mp.end()) {
            keys.erase(key_pos[k]);
        } else if (keys.size() >= n) {
            int lru_key = keys.back();
            keys.pop_back();
            mp.erase(lru_key);
            key_pos.erase(lru_key);
        }

        keys.push_front(k);
        mp[k] = v;
        key_pos[k] = keys.begin();
    }
};
