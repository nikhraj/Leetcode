class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        vector <int> ans;
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        vector <vector <int>> dp(n+1,vector <int>(m+1));
        
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            dp[i][nums[i-1]]++;
        }
        for(auto i:q)
        {
            auto v1 = dp[i[1]+1];
            auto v2 = dp[i[0]];
            int ans2=INT_MAX;
            int prev=-200;
            for(int i=0;i<=m;i++)
            {
                if(v1[i]!=v2[i])
                {
                    ans2=min(ans2,i-prev);
                    prev=i;
                }
            }
            ans2=ans2>=200?-1:ans2;
            ans.push_back(ans2);
        }
        
        return ans;
        
        
    } 
};