class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m<n)
        {
            swap(nums1,nums2);
            swap(m,n);
        }
        
        sort(nums1.begin(),nums1.end());
        set <int>  s;
        
        for(int i=0;i<n;i++)
        {
            int num = nums2[i];
            if(s.count(num))
                continue;
            int l=0,r=m-1;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(nums1[mid]==num)
                {
                    s.insert(num);
                    break;
                }
                else if(nums1[mid]<num)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        
        vector <int> ans(s.begin(),s.end());
        return ans;
        
    }
};