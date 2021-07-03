class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 1;
        if(n==2)
            return arr[0]==arr[1]?1:n;
        int ans=1;
        int l=0;
        int r=1;
        bool f=false;
        if(arr[0]<arr[1])
            f=true;
        int prev=0;
        while(r<n)
        {
            if(f)
            {
                if(arr[r-1]>arr[r])
                    f=false;
                else if(arr[r-1]==arr[r])
                    l=r;
                else
                    l=r-1;
            }
            else
            {
                if(arr[r-1]<arr[r])
                    f=true;
                else if(arr[r-1]==arr[r])
                    l=r;
                else
                    l=r-1;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};