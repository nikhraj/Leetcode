class Solution {
public:
    int secondHighest(string s) {
        set <int> ans;
        
        for(char c:s)
        {
            if(isdigit(c))
            {
                ans.insert(c-'0');
            }
        }
        if(!ans.empty())
        {
            ans.erase(*ans.rbegin());
        }
        
        return ans.empty()?-1:*ans.rbegin();
    }
};