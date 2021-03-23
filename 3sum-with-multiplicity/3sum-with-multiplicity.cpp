class Solution {
public:
    int MOD= 1e9+7;
    int threeSumMulti(vector<int>& nums, int target) {
        vector <int> m(101,0);
        int ans=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int new_target= target-nums[i];
            memset(&m[0], 0, 101 * sizeof m[0]);
            for(int j=i+1;j<nums.size();j++)
            {
                if(new_target-nums[j]>=0&&new_target-nums[j]<101)
                {
                    ans=(ans+m[new_target-nums[j]])%MOD;
                }
                m[nums[j]]++;
            }
        }
        
        return ans;
    }
};