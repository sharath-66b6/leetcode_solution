class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> res(box[0].size() , vector<char> (box.size()));
        
        for(int i=0;i<box.size();i++)
        {
            int x,y;
            for(int j=0;j<box[0].size();j++)
            {
                if(box[i][j] == '#')
                {
                    x=j;
                    y=j+1;
                    while(y<box[0].size())
                    {
                        if(box[i][y] == '.')
                        {
                            box[i][x++] = '.';
                            box[i][y] = '#';
                        }
                        else if(box[i][y] == '*')
                        {
                            break;
                        }
                        y++;
                    }
                    j=y;
                }
            }
        }
        for(int i=0;i<box.size();i++)
        {
            for(int j=0;j<box[0].size();j++)
            {
                res[j][i]=box[i][j];
            }
        }
        for(int i=0;i<res.size();i++)
            reverse(res[i].begin(),res[i].end());
        return res;
    }
};