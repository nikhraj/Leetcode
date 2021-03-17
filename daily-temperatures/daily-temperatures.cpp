class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        deque <int> q;
        
        int n=nums.size();
        vector <int> ans(n,0);
        
        q.push_back(n-1);
        //ans[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            while(!q.empty()&&nums[q.back()]<=nums[i])
            {
                q.pop_back();
            }
            ans[i]=((q.empty()?i:q.back())-i);
            q.push_back(i);
        }
        
        return ans;
    }
};