class WordDictionary {
private:
    struct node {
        bool isEnd;
        vector<node*> child;

        node() {
            isEnd = false;
            child.assign(26, NULL);
        }
    };

    bool dfs(string word, int ind, node* n){
        if(ind == word.size() && n->isEnd){
            return true;
        }

        bool ans = false;
        for(int i=0;i<26;i++){
            if(n->child[i] != NULL && (word[ind] == '.' || word[ind] == i+'a')){
                ans = ans || dfs(word, ind+1, n->child[i]);
            }
        }
        return ans;
    }
public:
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* temp = root;
        for(auto c:word){
            if(temp->child[c-'a'] == NULL){
                temp->child[c-'a'] = new node();
            }
            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        node* temp = root;
        return dfs(word, 0, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */