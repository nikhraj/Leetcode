class Solution {
public:
    vector <vector <int>> dp;
    int m,n;
    
    int dfs(int i,int j,vector <vector <int>> &grid)
    {
        if(i==m||j==n)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==m-1&&j==n-1)
            return grid[i][j]<=0?1-grid[i][j]:1;
        
        int mini = min(dfs(i+1,j,grid),dfs(i,j+1,grid)) - grid[i][j];
        
        
        return dp[i][j] = mini<=0?1:mini;
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.resize(m,vector <int> (n,-1));
        return dfs(0,0,dungeon);
        
    }
};