class Solution {
public:
    string evaluate(string s, vector<vector<string>>& nums) {
        map <string,string> m;
        for(auto i:nums)
        {
            m[i[0]]=i[1];
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            string key="";
            if(s[i]=='(')
            {
                i++;
                while(s[i]!=')')
                {
                    key+=s[i];
                    i++;
                }
                if(m.count(key))
                ans+=m[key];
                else
                    ans+='?';
            }
            else
                ans+=s[i];
            
        }
        return ans;
    }
};