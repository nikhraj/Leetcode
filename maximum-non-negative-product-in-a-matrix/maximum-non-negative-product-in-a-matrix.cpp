#define ll long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD=1e9+7;
        int m=grid.size();
        int n=grid[0].size();
        
        vector <vector <pair<ll,ll>>> dp(m,vector <pair<ll,ll>> (n));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=1;i<m;i++)
        {
            grid[i][0]=grid[i][0]*grid[i-1][0];
            dp[i][0]={grid[i][0],grid[i][0]};
        }
        
        for(int i=1;i<n;i++)
        {
            grid[0][i]=grid[0][i]*grid[0][i-1];
            dp[0][i]={grid[0][i],grid[0][i]};
        }
       
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int val=grid[i][j];
                ll l1=dp[i-1][j].first*val;
                ll l2=dp[i][j-1].first*val;
                ll r1=dp[i-1][j].second*val;
                ll r2=dp[i][j-1].second*val;
                dp[i][j]={max({l1,l2,r1,r2}),min({l1,l2,r1,r2})};
            }
        }
        int ans=dp[m-1][n-1].first%MOD;
        return ans<0?-1:ans;
    }
};