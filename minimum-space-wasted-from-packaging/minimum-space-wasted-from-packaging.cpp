class Solution {
public:
    int minWastedSpace(vector<int>& nums, vector<vector<int>>& boxes) {
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;
        long ans = LONG_MAX;
        long sum = 0;
        for(int i:nums)
            sum+=i;
        
        for(auto &box:boxes)
        {
            sort(box.begin(),box.end());
            long temp = 0;
            if(nums[nums.size()-1]>box[box.size()-1])
                continue;
            int i=0;
            for(long b:box)
            {
                int j = upper_bound(nums.begin()+i,nums.end(),b)-nums.begin();
                temp+=b*(j-i);
                i=j;
            }
          
            ans=min(ans,temp);
        }
        
        
        //cout<<ans<<endl;
        
        return ans==LONG_MAX?-1:(ans-sum)%mod;
    }
};