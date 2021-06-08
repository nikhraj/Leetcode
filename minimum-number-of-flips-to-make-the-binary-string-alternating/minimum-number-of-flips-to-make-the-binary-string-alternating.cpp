class Solution {
public:
    int minFlips(string s) {
        s+=s;
        //string temp = s;
        int n=s.size();
        vector <int> c0(n+1),c1(n+1);
        string s2="";
        for(int i=1;i<=n;i++)
        {
            s2+=i&1?((s[i-1]-'0')^0)+'0':((s[i-1]-'0')^1)+'0';
            if(s2[i-1]=='0')
            {
                c0[i]+=c0[i-1]+1;
                c1[i]+=c1[i-1];
            }
            else
            {
                c1[i]+=c1[i-1]+1;
                c0[i]+=c0[i-1];
            }
            
        }
       // cout<<s2<<endl;
        
        int l=0;
        int r=n/2;
        int ans=INT_MAX;
        // for(int i:c0)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int i:c1)
        //     cout<<i<<" ";
        // cout<<endl;
        while(r<n)
        {
            ans=min(ans,min(c0[r]-c0[l],c1[r]-c1[l]));
            l++;
            r++;
        }
        
        //cout<<s<<endl;
        return ans;
    }
};