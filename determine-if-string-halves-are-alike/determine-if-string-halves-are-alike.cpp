class Solution {
public:
    
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    
    bool halvesAreAlike(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n/2;i++)
        {
            if(isvowel(s[i]))
                c++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(isvowel(s[i]))
                c--;
        }
        return c==0; 
    }
};