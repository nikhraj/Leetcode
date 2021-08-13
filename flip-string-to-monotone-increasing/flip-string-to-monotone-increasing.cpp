class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = INT_MAX;
        int n=s.size();
        vector <int> prefix(n+1),suffix(n+1);
        
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+(s[i]=='0');
        }
        
        for(int i=n-1;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+(s[i]=='1');
        }
        
        ans=min(ans,n-prefix[n]);
        ans=min(ans,n-suffix[0]);
        for(int i=1;i<n;i++)
        {
            // if(i==2)
            // {
            //     cout<<prefix[i]<<" "<<suffix[i]<<endl;
            ans=min(ans,i-prefix[i]+n-i-suffix[i]);
           // }
        }
        
        return ans;
        
    }
};