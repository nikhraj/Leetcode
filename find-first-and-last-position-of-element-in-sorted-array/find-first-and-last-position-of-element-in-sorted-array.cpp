class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1=lower_bound(nums.begin(),nums.end(),target);
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        if(find(nums.begin(),nums.end(),target)==nums.end())
            return {-1,-1};
        vector <int> ans;
        ans.push_back(int(it1-nums.begin()));
        ans.push_back(int(it2-nums.begin())-1);
        return ans;
        
    }
};