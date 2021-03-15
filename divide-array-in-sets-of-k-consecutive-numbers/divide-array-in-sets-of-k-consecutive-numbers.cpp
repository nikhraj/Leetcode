class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return 0;
        map <int,int> m;
        for(int i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            while(m[i.first]>0)
            {
                m[i.first]--;
                for(int j=1;j<k;j++)
                {
                    if(m.count(i.first+j))
                        m[i.first+j]--;
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
};