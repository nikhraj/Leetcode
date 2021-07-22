class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int first,second;
        int n=nums.size();
        int ans=0;
        // if(nums[0]>nums[n-1])
        // {
        //     first=nums[n-1];
        //     second=-1;
        //     for(int i=n-2;i>=0;i--)
        //     {
        //         if(nums[i]<first)
        //         {
        //             if(second!=-1)
        //             {
        //                 first=second;
        //             }
        //             ans=i;
        //         }
        //         else
        //         {
        //             second = max(second,nums[i]);
        //         }
        //     }
        //     return n-ans;
        // }
        
        first=nums[0];
        second=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<first)
                {
                    if(second!=-1)
                    {
                        first=second;
                    }
                    ans=i;
                }
                else
                {
                    second = max(second,nums[i]);
                }
        }
        return ans+1;
    }
};