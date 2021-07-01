class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        
        int ans;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int sum=0;
            for(int i:piles)
            {
                sum+=i/mid+(i%mid>0);
            }
            if(sum<=H)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
        
        
    }
};