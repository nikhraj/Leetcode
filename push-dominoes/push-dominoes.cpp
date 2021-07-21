class Solution {
public:
    string pushDominoes(string s) {
        string ans = s;
        int n=s.size();
        queue <int> q;
        vector <bool> vis(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.') 
            {
                q.push(i);
                vis[i]=true;
            }
        }
        
        
        while(!q.empty())
        {
            int s=q.size();
            string prev = ans;
            while(s--)
            {
                int i = q.front();
                q.pop();
                char c = prev[i];
                if(c=='L')
                {
                    if(i-1>=0&&!vis[i-1])
                    {
                        bool f1=true;
                        if(i-2>=0)
                        {
                            if(prev[i-2]=='R')
                                f1=false;
                        }
                        if(f1)
                        {
                           ans[i-1]='L';
                           q.push(i-1);
                        }
                        vis[i-1]=true; 
                    }
                }
                else
                {
                    if(i+1<n&&!vis[i+1])
                    {
                        bool f2=true;
                        if(i+2<n)
                        {
                            if(prev[i+2]=='L')
                                f2=false;
                        }
                        if(f2)
                        { 
                            ans[i+1]='R';
                            q.push(i+1);
                        }
                        vis[i+1]=true;
                    }
                }
            }
        }
        
        return ans;
    }
};