class Solution {
public:
    int majorityElement(vector<int>& nums) {
       //nt ans=0;
        vector <int> bits(32);
        
        for(int &i:nums)
        {
            for(int j=0;j<32;j++)
            {
                if(i&(1<<j))
                    bits[j]++;
            }
        }
        
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<32;i++)
        {
            if(bits[i]>(n/2))
                ans|=(1<<i);
        }
        return ans;
    }
};