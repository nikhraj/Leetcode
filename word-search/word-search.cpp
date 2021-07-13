class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        char c = word[0];
        m = board.size();
        n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==c)
                {
                    if(dfs(i,j,word,board))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i,int j,string word,vector <vector <char>> &board)
    {
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[0]||board[i][j]=='-1')
            return false;
        if(word.size()==1)
            return true;
        
        char c=board[i][j];
        board[i][j]='-1';
        word = word.substr(1);
        bool f = dfs(i-1,j,word,board)||dfs(i+1,j,word,board)||dfs(i,j-1,word,board)||dfs(i,j+1,word,board);
        board[i][j]=c;
            
        return f;
        
    }
};