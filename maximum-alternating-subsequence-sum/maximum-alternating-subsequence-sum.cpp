class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector <array <long long,2>> dp(n+1,{0,0});
        for(int i=0;i<n;i++)
        {
            dp[i+1][0]=max(dp[i][0],dp[i][1]+nums[i]);
            dp[i+1][1]=max(dp[i][1],dp[i][0]-nums[i]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};