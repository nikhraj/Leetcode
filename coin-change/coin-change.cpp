class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount+1,10000);
        dp[0]=0;
        
        for(int &i:coins)
        {
            for(int j=i;j<=amount;j++)
                dp[j]=min(dp[j],1+dp[j-i]);
        }
        
        return dp[amount]>=10000?-1:dp[amount];
    }
};