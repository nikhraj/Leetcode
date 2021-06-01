class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        long ans;
        while(l<=r)
        {
            long mid = (l+r)/2;
            long long prod = mid*mid;
           
            if(prod<=x)
            {
                ans=max(ans,mid);
                l = mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};