class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l = 0,r=0;
        int ans=0,c=0;
        vector <int> m(26,0);
        while(r<n)
        {
            ++m[s[r]-'A'];
            c = max(c,m[s[r]-'A']);
            r++;
            while(r-l-c>k)
            {
                --m[s[l++]-'A'];
            }
            ans=max(ans,r-l);
        }
        return ans;
        
    }
};