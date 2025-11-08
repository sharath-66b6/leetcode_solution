class Solution {
private:
    int diff(string a, string b){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i])
                c++;
        }
        return c;
    }
    int path(string start, string end, unordered_map<string, vector<string>>& graph){
        queue<pair<string, int> > q;
        q.push({start, 1});
        unordered_set<string> vis;
        vis.insert(start);
        while(!q.empty()){
            string s = q.front().first;
            int t = q.front().second;
            q.pop();
            if(s == end) return t;
            for(auto n : graph[s]){
                if(vis.count(n)) continue;
                q.push({n,t+1});
                vis.insert(n);
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        wordList.push_back(beginWord);
        int n = wordList.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(diff(wordList[i], wordList[j]) == 1){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(graph.find(endWord) == graph.end()) return 0;

        return path(beginWord, endWord, graph);
    }
};