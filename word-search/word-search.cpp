class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c = board[i][j];
                if(word[0]==c)
                {
                    if(dfs(i,j,board,word))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int i,int j,vector <vector <char>> &grid,string word)
    {
        if(word.size()==0)
            return true;
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=word[0])
        {
            return false;
        }
        char c = grid[i][j];
        grid[i][j]='1';
        
        word = word.substr(1);
        bool f = dfs(i-1,j,grid,word)|| dfs(i+1,j,grid,word)|| dfs(i,j-1,grid,word)|| dfs(i,j+1,grid,word);
        grid[i][j] = c;
        return f;
        
    }
    
};