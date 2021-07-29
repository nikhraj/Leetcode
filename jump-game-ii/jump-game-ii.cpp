class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int prev = 0;
        int global = 0;
        
        for(int i=0;i<n-1;i++)
        {
            global=max(global,i+nums[i]);
            if(i==prev)
            {
                ans++;
                prev=global;
            }
            
        }
        
        return ans;
    }
};