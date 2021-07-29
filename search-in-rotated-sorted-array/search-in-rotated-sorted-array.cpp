class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r=nums.size()-1;
        int first = nums[0];
        bool target_big = target>=first;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int ele = nums[mid];
            if(ele==target)
                return mid;
            bool ele_big = ele>=first;
            
            if(ele_big==target_big)
            {
                if(ele<target)
                    l=mid+1;
                else
                    r=mid-1;
            }
            else
            {
                if(ele_big)
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            
        }
        return -1;
    }
};