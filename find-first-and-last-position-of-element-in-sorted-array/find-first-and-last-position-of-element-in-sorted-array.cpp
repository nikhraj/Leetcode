class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int ans1=-1,ans2=-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid]<target)
            {
                i=mid+1;
            }
            else if(nums[mid]>target)
            {
                j=mid-1;
            }
            else
            {
                ans1=mid;
                j=mid-1;
            }
                
        }
        
        i=0,j=nums.size()-1;
        
        
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(nums[mid]>target)
            {
                j=mid-1;
            }
            else if(nums[mid]<target)
            {
                i=mid+1;
            }
            else
            {
                ans2=mid;
                i=mid+1;
            }
        }
        
        
        
        return {ans1,ans2};
        
        
    }
};