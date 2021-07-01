class Solution {
public:
    int n;
    vector <int> prefix;
    int findBestValue(vector<int>& nums, int target) {
        int ans=-1;
        n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=target;
        prefix.resize(n,0);
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        if(prefix[n-1]<=target)
        {
            return nums[n-1];
        }
        
        int possible_target = INT_MAX;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int get_target = check(mid,nums,target);
            if(get_target>target)
            {
                if(abs(get_target-target)<possible_target)
                {
                    ans=mid;
                    possible_target = abs(get_target-target);
                }
                r=mid-1;
            }
            else
            {
                if(abs(get_target-target)<possible_target)
                { 
                    ans=mid;
                    possible_target = abs(get_target-target);
                }
                l=mid+1;
            }
        }
        
        
        return ans;
    }
    
    int check(int mid,vector <int> &nums,int target)
    {
        int index = upper_bound(nums.begin(),nums.end(),mid)-nums.begin();
       // cout<<mid<<" "<<index<<endl;
        if(index==0)
                return n*mid;
        if(index<n)
        {
            
            return (n-index)*mid+prefix[index-1];
        }
        return prefix[n-1];
    }
};