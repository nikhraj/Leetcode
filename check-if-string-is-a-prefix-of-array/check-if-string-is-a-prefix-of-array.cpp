class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans="";
        int n=s.size();
        int i=0;
        while(ans.size()<n&&i<words.size())
        {
            ans+=words[i++];
        }
        return ans==s;
    }
};