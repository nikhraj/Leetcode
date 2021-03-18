class Solution {
public:
    int heightChecker(vector<int>& nums) {
       vector <int> temp = nums;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=temp[i])
                ans++;
        }
        
        return ans;
        
    }
};