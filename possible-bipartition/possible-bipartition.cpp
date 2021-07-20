class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map <int,vector <int>> m;
        
        for(auto &i:dislikes)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        
        vector <int> color(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                queue <int> q;
                q.push(i);
                color[i]=0;
                
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(int v:m[u])
                    {
                        
                        if(color[v]==-1)
                        {
                            q.push(v);
                            color[v]=1-color[u];
                        }
                        else if(color[u]==color[v])
                            return false;
                    }
                    
                }
                
            }
        }
        
        return true;
    }
};