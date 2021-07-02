class Solution {
public:
    vector <bool> vis;
    int removeStones(vector<vector<int>>& stones) {
        int c=0;
        int n=stones.size();
        vis.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                dfs(i,stones);
                c++;
            }
        }
        return n-c;
    }

    void dfs(int i,vector <vector <int>> &stones)
    {
       // vis[i]=true;
        auto co = stones[i];
        for(int j=0;j<stones.size();j++)
        {
            if(!vis[j])
            {
                if(stones[j][0]==co[0]||stones[j][1]==co[1])
                {
                    vis[j]=true;
                    dfs(j,stones);
                }
            }
        }
    }

};