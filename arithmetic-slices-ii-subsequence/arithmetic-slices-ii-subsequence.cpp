class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector <unordered_map <long,int>> dp(n);
        
        for(int i=1;i<n;i++)
        {
            long num=nums[i];
            for(int j=0;j<i;j++)
            {
                int a = dp[j][num-nums[j]];
                int b = dp[i][num-nums[j]];
                //cout<<a<<" "<<b<<endl;
                ans+=a;
                dp[i][num-nums[j]]=a+b+1;
            }
        }
        
        return ans;
    }
};