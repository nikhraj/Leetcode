class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector <int> mini(nums.size(),INT_MAX);
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            mini[i]=min(nums[i],mini[i-1]);
        
        
        for(int j=1;j<nums.size()-1;j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(nums[j]<nums[k]&&mini[j-1]<nums[j])
                    return true;
            }
        }
        
        return false;
    }
};