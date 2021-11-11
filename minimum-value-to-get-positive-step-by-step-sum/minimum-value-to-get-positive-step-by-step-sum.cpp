class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = nums[0];
        int mini = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            mini = min(mini,sum);
        }
        
        return mini<0?abs(mini)+1:1;
    }
};