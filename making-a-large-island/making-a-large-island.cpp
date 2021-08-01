class Solution {
public:
    int m,n,c;
    vector <int> area;
    int largestIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        c=2;
        int ans=0;
        int fin = 0;
        vector <array <int,2>> zeroes;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans = dfs(i,j,grid);
                    fin = max(fin,ans);
                    area.push_back(ans);
                    c++;
                }
                else if(grid[i][j]==0)
                    zeroes.push_back({i,j});
                    
            }
        }
        for(auto &z:zeroes)
        {
            //cout<<1<<endl;
            int co=1;
            unordered_set <int> vis;
            int i = z[0],j=z[1];
            if(i-1>=0)
            {
                if(grid[i-1][j]&&!vis.count(grid[i-1][j]))
                {
                    co+=area[grid[i-1][j]-2];
                    vis.insert(grid[i-1][j]);
                }
            }
            if(i+1<m)
            {
                if(grid[i+1][j]&&!vis.count(grid[i+1][j]))
                {
                    co+=area[grid[i+1][j]-2];
                    vis.insert(grid[i+1][j]);
                }
            }
            if(j-1>=0)
            {
                if(grid[i][j-1]&&!vis.count(grid[i][j-1]))
                {
                    co+=area[grid[i][j-1]-2];
                    vis.insert(grid[i][j-1]);
                }
            }
            if(j+1<n)
            {
                if(grid[i][j+1]&&!vis.count(grid[i][j+1]))
                {
                    co+=area[grid[i][j+1]-2];
                    vis.insert(grid[i][j+1]);
                }
            }
            fin=max(fin,co);
        }
        return fin;
    }
    
    int dfs(int i,int j,vector <vector <int>> &grid)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1)
            return 0;
        grid[i][j]=c;
        return 1+dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j-1,grid)+dfs(i,j+1,grid);
    }
};