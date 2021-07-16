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
        
        for(r=0;r<wn;r++)
        {
            m[s[r]-'a']++;
        }
        bool f=true;
        auto temp = m;
        for(char c:p)
            {
                if(--temp[c-'a']<0)
                {
                    f=false;
                    break;
                }
            }
        if(f)
            ans.push_back(l);
        
        while(r<n)
        {
            m[s[l++]-'a']--;
            m[s[r++]-'a']++;
            f=true;
            temp=m;
            for(char c:p)
            {
                if(--temp[c-'a']<0)
                {
                    f=false;
                    break;
                }
            }
            if(f)
                ans.push_back(l);
        }
        
        
        return ans;
    }
};