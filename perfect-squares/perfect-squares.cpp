class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1,INT_MAX);
        vector <int> coins;
        int i=1;
        while(i*i<(n+1))
        {
            coins.push_back(i*i);
            i++;
        }
        dp[0]=0;
        for(int i:coins)
        {
            
            for(int j = i;j<=n;j++)
            {
                dp[j]=min(dp[j],1+dp[j-i]);
            }
        }
        
        return dp[n];
    }
    
};