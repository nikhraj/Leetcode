class Solution {
public:
    int ans=0;
    int n;
    int findTargetSumWays(vector<int>& nums, int S) {
        n=nums.size();
        dfs(0,0,nums,S);
        return ans;
    }
    void dfs(int sum,int i,vector <int> &nums,int target)
    {
        if(i==n)
        {
            //cout<<1<<endl;
            if(sum==target)
                ans++;
            return;
        }
        dfs(sum+nums[i],i+1,nums,target);
        dfs(sum-nums[i],i+1,nums,target);
    }
};