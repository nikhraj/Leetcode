class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector <int> &a,vector <int> &b){return a[0]<b[0];});
        
        vector <vector <int>> ans;
        int start=-1,end=-1;
        for(auto i:nums)
        {
            if(start==-1&&end==-1)
            {
                start=i[0];
                end=i[1];
            }
            else if(i[0]<=end)
            {
                end=max(end,i[1]);
            }
            else
            {
                ans.push_back({start,end});
                start=i[0];
                end=i[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};