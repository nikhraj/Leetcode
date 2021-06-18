class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int c=0;
        int l=0,r=0;
        int n=nums.size();
        int prev=0;
        while(r<n)
        {
            if(nums[r]<left)
                c+=prev;
            else if(nums[r]>right)
            {
                prev=0;
                l=r+1;
            }
            else
            {
                prev=r-l+1;
                c+=prev;
            }
            r++;
        }
        
        
        return c;
    }
};