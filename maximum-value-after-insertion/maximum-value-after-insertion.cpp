#define ll long long
class Solution {
public:
    string maxValue(string s, int x) {
        bool flag = false;
        char c = x +'0';
        if(s[0]=='-')
        {
            flag=true;
            s=s.substr(1);
        }
        
        for(int i=0;i<s.size();i++)
        {
            
            if(flag)
            {
                if(s[i]-'0'>x)
                {
                    return "-"+s.substr(0,i)+(c)+s.substr(i);
                }
            }
            else
            {
               if(s[i]-'0'<x)
                {
                    return s.substr(0,i)+(c)+s.substr(i);
                } 
            }
        }
        
        return flag?"-"+s.substr(0)+c:s.substr(0)+c;
        
    }
};