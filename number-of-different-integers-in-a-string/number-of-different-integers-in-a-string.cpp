class Solution {
public:
    int numDifferentIntegers(string s) {
        set <string> ans;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                string temp="";
                while(isdigit(s[i]))
                {
                    temp+=s[i];
                    i++;
                }
                temp.erase(0, temp.find_first_not_of('0'));
                ans.insert(temp);
            }
        }
        return ans.size();
    }
};