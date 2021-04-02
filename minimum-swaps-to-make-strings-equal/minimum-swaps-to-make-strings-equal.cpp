class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.size()!=s2.size())
            return -1;
        vector <int> m1(2),m2(2);
        
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                m1[s1[i]-'x']++;
                m2[s2[i]-'x']++;
            }
        }
        
        if(m1[0]+m1[1]!=m2[0]+m2[1]||(m1[0]+m1[1])&1)
            return -1;
        
        int ans=0;
        while(true)
        {
            if(m2[1]>=2&&m1[0]>=2)
            {
                m2[1]-=2;
                m1[0]-=2;
                ans++;
            }
            else if(m2[0]>=2&&m1[1]>=2)
            {
                m1[1]-=2;
                m2[0]-=2;
                ans++;
            }
            else if(m1[0]!=0&&m2[0]!=0)
            {
                ans+=2;
                break;
            }
            else
                break;
        
        }
        
        return ans;
    }
};