class Solution {
public:
    int m,n;
    vector <int> dirs={0,-1,0,1,0};
    vector <vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& nums) {
        m=nums.size();
        n=nums[0].size();
        dp.resize(m,vector<int>(n));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dfs(i,j,nums,INT_MIN));
            }
        }
        return ans;
    }
    int dfs(int i,int j,vector <vector <int>> &nums,int prev)
    {
        if(i<0||j<0||i>=m||j>=n||nums[i][j]<=prev)
            return 0;
        if(dp[i][j]!=0)
            return dp[i][j];
        int ans=0;
        for(int k=1;k<5;k++)
        {
            ans=max(ans,1+dfs(i+dirs[k-1],j+dirs[k],nums,nums[i][j]));
        }
        
        return dp[i][j]=ans;
    }
    
};