class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i<=n;i++)
        {
            int i1 = i*i;
            for(int j=i1;j<=n;j++)
            {
                
                if(dp[j-i1]>=0)
                {
                    dp[j] = min(dp[j],1+dp[j-i1]);
                }
            }
            
        }
        return dp[n];
    }
};