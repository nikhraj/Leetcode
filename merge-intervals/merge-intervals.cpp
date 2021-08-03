class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector <int> &a,vector <int> &b){
            return a[0]<b[0];
        });
        vector <vector <int>> ans;
        int start = nums[0][0];
        int end = nums[0][1];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][0]<=end)
            {
                end=max(end,nums[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=nums[i][0];
                end=nums[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};