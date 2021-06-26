class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int ans = 0;
        for(int bit=0;bit<32;bit++)
        {
            int a=0,b=0;
            for(int i=0;i<=n;i++)
            {
                if(nums[i]&(1<<bit))
                    a++;
                if(i>0&&i&(1<<bit))
                    b++;
            }
            if(a>b)
                ans+=(1<<bit);
        }
        
        return ans;
        
        
        
    }
};