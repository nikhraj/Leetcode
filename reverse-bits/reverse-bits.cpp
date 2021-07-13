class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        
        for(int i=31;i>=0;i--)
        {
            int temp = n&(1<<(31-i));
            if(temp)
                ans|=(1<<i);
        }
        return ans;
    }
};