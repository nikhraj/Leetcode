class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0;
        int index=0;
       // int prev=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                if((i-1)!=0)
                {
                    int temp=nums[i-2];
                    if(temp>nums[i])
                    {
                        nums[i]=nums[i-1];
                    }
                }
               // prev=nums[i-1];
                c++;
            }
            
        }
        return c<=1;
    }
};