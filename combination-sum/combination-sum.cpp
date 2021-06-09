class Solution {
public:
    vector <vector <int>> ans;
    
    void dfs(int i,int target,vector <int> &nums,vector <int> v)
    {
        if(i>=nums.size()||target<0)
        {
            if(target==0)
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        dfs(i,target-nums[i],nums,v);
        v.erase(v.end()-1);
        dfs(i+1,target,nums,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,target,nums,{});
        return ans;
    }
};