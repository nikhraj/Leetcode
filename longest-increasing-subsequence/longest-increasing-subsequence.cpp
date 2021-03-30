class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp;
        dp.push_back(nums[0]);
        int index=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>dp[index])
            {
                dp.push_back(nums[i]);
                index++;
            }
            else
            {
                int inde=upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                //cout<<inde<<" ";
                if(inde<dp.size()&&inde==0||nums[i]!=dp[inde-1])
                    dp[inde]=nums[i];
            }
            
        }
        //for(int i:dp)
          //  cout<<i<<" ";
        return dp.size();
        
    }
};