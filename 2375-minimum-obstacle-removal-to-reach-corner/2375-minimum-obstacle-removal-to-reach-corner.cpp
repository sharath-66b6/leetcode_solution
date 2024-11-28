class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> mn(m, vector<int> (n, INT_MAX));
        mn[0][0] = 0;

        deque<array<int, 3>> deque;
        deque.push_back({0,0,0});

        while(!deque.empty())
        {
            auto curr=deque.front();
            deque.pop_front();
            int cost=curr[0], x=curr[1], y=curr[2];

            for(auto dir: directions){
                int i = x+dir[0], j = y+dir[1];

                bool isvalid = (i >= 0) && (j >= 0) && (i < grid.size()) && (j < grid[0].size());
                if(isvalid && mn[i][j] == INT_MAX)
                {
                    if(grid[i][j] == 1)
                    {
                        
                        mn[i][j] = cost+1;
                        deque.push_back({cost+1, i, j});
                    }
                    else{
                        mn[i][j] = cost;
                        deque.push_front({cost, i, j});
                    }
                }
            }
        }
        return mn[m-1][n-1];
    }
};