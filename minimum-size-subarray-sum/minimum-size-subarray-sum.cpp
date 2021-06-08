class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        
        deque <int> q;
        int sum=0;
        int i = 0, j=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            //q.push_back(nums[i]);
            if(sum>=target)
            {
                //ans=min(ans,i-j);
                while(sum>=target)
                {
                    sum-=nums[j];
                    ans=min(ans,i-j+1);
                    j++;
                }
                //if(sum==target)
                
            }
            i++;
        }
        
        
        
        return ans==INT_MAX?0:ans;
        
    }
};