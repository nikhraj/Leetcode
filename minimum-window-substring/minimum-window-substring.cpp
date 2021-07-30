class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        int count = n;
        int l=0,r=0;
        vector <int> ma(58);
        for(char c:t)
        {
            ma[c-'A']++;
        }
        string ans;
        int c=INT_MAX;
        while(r<m)
        {
            if(--ma[s[r++]-'A']>=0)
                count--;
            while(count==0)
            {
                if(r-l<c)
                {
                    c=r-l;
                    ans=s.substr(l,r-l);
                }
                if(++ma[s[l++]-'A']>=1)
                    count++;
            }
        }
        
        return ans;
    }
};