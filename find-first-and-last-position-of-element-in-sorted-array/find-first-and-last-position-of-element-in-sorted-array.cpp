class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid1,mid2;
        
        int l=0,r=nums.size()-1;
        int ans1=-1,ans2=-1;
        while(l<=r)
        {
            mid1=(l+r)/2;
            if(nums[mid1]>target)
            {
                r=mid1-1;
            }
            else if(nums[mid1]==target)
            {
                ans1=mid1;
                r=mid1-1;
            }
            else
                l=mid1+1;
        }
        
        l=0,r=nums.size()-1;
        
        while(l<=r)
        {
            mid2=(l+r)/2;
            if(nums[mid2]<target)
            {
                l=mid2+1;
            }
            else if(nums[mid2]==target)
            {
                ans2=mid2;
                l=mid2+1;
            }
            else
                r=mid2-1;
        }
        
        
        return {ans1,ans2};
        
    }
};