class Solution {
public:
    int hammingDistance(int x, int y) {
        int xo = x^y;
        int ans=0;
        while(xo)
        {
            if(xo&1)
                ans++;
            xo>>=1;
        }
        return ans;      
    }
};