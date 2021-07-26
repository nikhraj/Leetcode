class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int &i:nums)
            target+=i;
        if(target&1)
            return false;
        target/=2;
        sort(nums.begin(),nums.end());
        vector <int> dp(target+1);
        vector <int> prev;
        for(int &i:nums)
        {
            prev = dp;
            if(i>target)
            {
                return false;
            }
            for(int j=i+1;j<=target;j++)
            {
                if(prev[j-i])
                {
                    //cout<<i<<" "<<j<<endl;
                    dp[j]++;
                }
                
            }
            dp[i]++; 
        }
        
        //cout<<dp[target]<<" ";
        
        
        
        return dp[target]>0;
    }
};