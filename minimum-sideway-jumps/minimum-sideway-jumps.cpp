class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector <vector <int>> dp(n,vector <int> (3,INT_MAX));
        dp[0][0]=1;
        dp[0][1]=0;
        dp[0][2]=1;
        for(int i=0;i<n-1;i++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==obstacles[i+1]-1)
                    continue;
                if(dp[i][k]!=INT_MAX)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(j==obstacles[i+1]-1)
                            continue;
                        dp[i+1][j]=min(dp[i+1][j],dp[i][k]+(abs(k-j)>0));
                    } 
                }
                
            }
        }
        
        return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
        
        
    }
};