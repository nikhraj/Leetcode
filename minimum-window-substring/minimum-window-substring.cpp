class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> m(58,0);
        for(char c:t)
        {
            m[c-'A']++;
        }
        int count = t.size();
        int n = s.size();
        int l=0,r=0;
        string ans = "";
        int mini = n+1;
        while(r<n)
        {
            if(--m[s[r++]-'A']>=0)
                count--;
            while(count==0)
            {
                if((r-l)<mini)
                {
                    mini=r-l;
                    ans = s.substr(l,r-l);
                }
                if(++m[s[l++]-'A']>0)
                    count++;
            }
        }
        
        return ans;
        
        
    }
};