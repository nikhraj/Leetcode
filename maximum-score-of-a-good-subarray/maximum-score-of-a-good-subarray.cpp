class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int mini=nums[i];
        int ans=nums[i];
        int n=nums.size();
        while(i>0||j<n-1)
        {
            if(i==0)
                j++;
            else if(j==n-1)
                i--;
            else if(nums[i-1]<nums[j+1])
            {
                j++;
            }
            else
            {
                i--;
            }
            mini=min({mini,nums[i],nums[j]});
            ans=max(ans,mini*(j-i+1));
            
        }
        return ans;
    }
};