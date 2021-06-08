class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        
        deque <int> q;
        int sum=0;
        int i = 0, j=nums.size();
        while(i<j)
        {
            sum+=nums[i];
            q.push_back(nums[i]);
            if(sum>=target)
            {
                ans=min(ans,int(q.size()));
                while(sum>=target)
                {
                    sum-=q.front();
                    q.pop_front();
                    ans=min(ans,int(q.size())+1);
                }
                //if(sum==target)
                
            }
            i++;
        }
        
        
        
        return ans==INT_MAX?0:ans;
        
    }
};