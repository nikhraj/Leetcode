class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int ans;
        
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            
            if(mid==0||nums[mid]>nums[mid-1])
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
            
        }
        return ans;
    }
};