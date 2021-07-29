class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r=nums.size()-1;
        int last = nums[r];
        int ans;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]>last)
            {
                l = mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return nums[ans];
    }
};