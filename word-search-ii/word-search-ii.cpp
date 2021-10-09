class TrieNode {
    public:
        
        string word;
        vector <TrieNode *> next;
        TrieNode()
        {
            word = "";
            next.resize(26,NULL);
        }
};


class Solution {
public:
    TrieNode *root;    
    set <string> ans;
    int m,n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        root = new TrieNode();
        for(string &s:words)
        {
            auto p = root;
            for(char c:s)
            {
                if(!p->next[c-'a'])
                    p->next[c-'a']=new TrieNode();
                p = p->next[c-'a'];
            }
            p->word = s;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(i,j,board,root);
            }
        }
        
        return vector <string> (ans.begin(),ans.end());
        
    }
    void dfs(int i,int j,vector <vector <char>> &grid,TrieNode *p)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='1')
            return;
        char c = grid[i][j];
       
        if(!p->next[c-'a'])
        {
            return;
        }
        if(p->next[c-'a']->word!="")
        {
            //cout<<"1"<<endl;
            ans.insert(p->next[c-'a']->word);
        }
        
        grid[i][j]='1';
        p = p->next[c-'a'];
        dfs(i-1,j,grid,p);
        dfs(i+1,j,grid,p);
        dfs(i,j-1,grid,p);
        dfs(i,j+1,grid,p);
        grid[i][j]=c;
    }
};
