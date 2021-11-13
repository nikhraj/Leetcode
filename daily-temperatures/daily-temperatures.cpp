class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        deque <int> q;
        
        int n=nums.size();
        vector <int> ans(n,0);
        q.push_back(0);
        
        for(int i=1;i<n;i++)
        {
            while(!q.empty()&&nums[q.back()]<nums[i])
            {
                ans[q.back()]=i-q.back();
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return ans;
    }
};