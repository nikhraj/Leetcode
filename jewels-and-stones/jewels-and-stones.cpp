class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        set<char> s;
        for(char c:jewels)
            s.insert(c);
        for(char c:stones)
        {
            if(s.find(c)!=s.end())
                ans++;
        }
        
        return ans;
        
    }
};