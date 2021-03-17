class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        //int ans=INT_MAX;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
                nums[i][j]+=min({nums[i-1][max(0,j-1)],nums[i-1][j],nums[i-1][min(j+1,n-1)]});
        }
        
        return *min_element(nums[n-1].begin(),nums[n-1].end());        
    }
};