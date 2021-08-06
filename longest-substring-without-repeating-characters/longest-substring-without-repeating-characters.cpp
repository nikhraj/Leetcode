class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
       unordered_map <int,int> m;
        int ans=0;
        int n=s.size();
        
        while(r<n)
        {
            if(m[s[r]-'a']==0)
            {
                m[s[r]-'a']++;
                r++;
            }
            else
            {
                ans=max(ans,r-l);
                
                while(s[l]!=s[r])
                {
                    m[s[l]-'a']--;
                    l++;
                }
                m[s[l]-'a']--;
                l++;
                m[s[r]-'a']++;
                r++;
            }
        }
           ans=max(ans,r-l);
        
        return ans;
    }
};