class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,n+1);
        dp[0]=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n&&j<=(i+nums[i]);j++)
            {
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        // for(int i:dp)
        //     cout<<i<<endl;
        return dp[n-1];
        
    }
};