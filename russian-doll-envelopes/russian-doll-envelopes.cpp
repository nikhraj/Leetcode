class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector <int> &a,vector <int> &b){return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];});
        
        vector <int> dp;
        for(auto i:nums)
        {
            auto it=lower_bound(dp.begin(),dp.end(),i[1]);
            if(it==dp.end())
                dp.push_back(i[1]);
            else
                *it=i[1];
        }
        
        return dp.size();
        
        
    }
};