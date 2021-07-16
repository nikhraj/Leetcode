class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        
        int n=s.size();
        int wn = p.size();
        if(n<wn)
            return ans;
        vector <int> m(26);
        
        int l=0,r=0;
        
        for(char c:p)
        {
            m[c-'a']++;
        }
        r=0;
        int count = wn;
        while(r<n)
        {
            if(--m[s[r]-'a']>=0)
            {
                count--;
            }
            r++;
            if(count==0)
                ans.push_back(l);
            if((r-l)==wn)
            {
                if(++m[s[l]-'a']>0)
                    count++;
                l++;
            }
            
        }
        
        
        return ans;
    }
};