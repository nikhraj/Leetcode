class Solution {
public:
    int m,n,c,nc;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m=grid.size();
        if(m==0)
            return grid;
        n=grid[0].size();
        c=grid[r0][c0];
        nc=color;
        if(c==nc)
            return grid;
        dfs(r0,c0,grid);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=abs(grid[i][j]);
            }
        }
        return grid;    
    }
    
    void dfs(int i,int j,vector <vector <int>> &grid)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=c)
            return;
        //int count=0;
        bool f=false;
        if(i==0||j==0||i==m-1||i==n-1||abs(grid[i-1][j])!=c||abs(grid[i+1][j])!=c||abs(grid[i][j-1])!=c||abs(grid[i][j+1])!=c)
            f=true;
        grid[i][j]=-c;
        
        
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        
        if(f)
           grid[i][j]=nc;
        //cout<<i<<" "<<j<<" "<<count<<endl;
       // return 1;
    }    
    
};