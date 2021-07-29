class Solution {
public:
    bool canJump(vector<int>& nums) {
        int global_max = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i>global_max)
            {
                return false;
            }
            global_max = max(global_max,i+nums[i]);
            
        }
    
        return true;
    }
};