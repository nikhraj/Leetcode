class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(m*k>n)
            return -1;
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<n;i++)
        {
            l=min(l,nums[i]);
            r=max(r,nums[i]);
        }
        
        int ans=-1;
        //cout<<check(3,nums,m,k)<<endl;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid,nums,m,k))
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
    
    bool check(int day,vector <int> &nums,int m,int k)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]>day)
                c=0;
            else
                c++;
            if(c==k)
            {
                //cout<<i<<endl;
                m--;
                c=0;
            }
            if(m==0)
                return true;
        }
        return false;
    }
}; 
