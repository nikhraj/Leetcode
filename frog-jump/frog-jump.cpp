class Solution {
public:
    bool canCross(vector<int>& nums) {
        if(nums[1]-nums[0]!=1)
            return false;
        map <int,set<int>> m;
        
        for(int i:nums)
            m[i]={};
        m[0].insert(1);
        for(int i:nums)
        {
            for(int j:m[i])
            {
                if(m.count(i+j))
                {
                    m[i+j].insert(j);
                }
                if(m.count(i+j-1))
                {
                   m[i+j-1].insert(j-1); 
                }
                if(m.count(i+j+1))
                {
                    m[i+j+1].insert(j+1);
                }
            }            
        }
        
        return m[nums[nums.size()-1]].size()!=0;
    }
};