class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1,r=INT_MIN;
        for(int i:nums)
        {
            //l=min(l,i);
            r=max(r,i);
        }
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int sum=0;
            
            for(int i:nums)
            {
                sum+=i/mid+(i%mid>0);
            }
            if(sum<=threshold)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    
        return ans;
        
    }
};