class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0,r=0;
        int n = nums.size();
        int sum=0;
        int ans = INT_MAX;
        while(r<n)
        {
            sum+=nums[r++];
            
            while(sum>=target)
            {
                ans=min(ans,r-l);
                sum-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};