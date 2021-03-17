class Solution {
public:
    vector <vector <int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        comb(0,target,{},nums);
        return ans;
    }
    
    void comb(int index,int target,vector <int> path,vector <int> &nums)
    {
        if(target==0)
        {
            ans.push_back(path);
            return;
        }
        if(target<0||index==nums.size())
            return;
        
        
        for(int i=index;i<nums.size();i++)
        {
            if(i==index||nums[i]!=nums[i-1])
            {
                path.push_back(nums[i]);
                comb(i+1,target-nums[i],path,nums);
                path.erase(path.end()-1);
            }
        }
        
            
    }
    
    
};
