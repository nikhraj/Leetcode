class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        
        int l=0,r=0;
        for(int i:nums)
        {
            l=max(l,i);
            r+=i;
        }
        
        int ans;
        //check(11,nums,days);
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,nums,days))
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
    bool check(int mid,vector <int> &nums,int days)
    {
        int ans=0;
        for(int i:nums)
        {
            ans+=i;
            if(ans>mid)
            {
                //cout<<ans<<" ";
                days--;
                ans=i;
            }
            if(days<0)
                return false;
        }
        days--;
        
        return days>=0;
    }
    
};
