class Solution {
public:
    int minSteps(int n) {
        vector <int> dp(n+3,INT_MAX);
        dp[1]=0;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=2;i<=n;i++)
        {
            if(dp[i]==INT_MAX)
                dp[i]=i;
            for(int j=2;(j*i)<=n;j++)
            {
                //cout<<i<<" "<<j<<endl;
                dp[i*j] = min(dp[i*j],dp[i]+j);
            }
        }
        
        return dp[n];
        
    }
};