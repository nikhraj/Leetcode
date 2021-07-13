class Solution {
public:
    class TrieNode
    {
        public:
            vector <TrieNode *> next;
            bool word;
            TrieNode()
            {
                next.resize(26,NULL);
                word=false;
            }
    };
    
    TrieNode *root;
    int m,n;
    void insert(string word)
    {
        auto p=root;
        for(char c:word)
        {
            if(!p->next[c-'a'])
                p->next[c-'a']=new TrieNode();
            p=p->next[c-'a'];
        }
        p->word= true;
    }
    
    vector <string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        m = board.size();
        n = board[0].size();
        
        for(string s:words)
            insert(s);
       // dfs(0,0,board,root,"");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(i,j,board,root,"");
            }
        }
        
        return ans;
        
    }
    
    void dfs(int i,int j,vector <vector <char>> &board,TrieNode *p,string s)
    {
        if(i<0||j<0||i>=m||j>=n)
            return;
        
        char c=board[i][j];
        if(c=='1'||!p->next[c-'a'])
            return;
        s+=c;
        
        p=p->next[c-'a'];
        if(p->word)
        {
            ans.push_back(s);
            p->word=false;
        }
        
        board[i][j]='1';
            
        dfs(i-1,j,board,p,s);
        dfs(i+1,j,board,p,s);
        dfs(i,j-1,board,p,s);
        dfs(i,j+1,board,p,s); 
        
        board[i][j]=c;
            
        
        
    }
    
};