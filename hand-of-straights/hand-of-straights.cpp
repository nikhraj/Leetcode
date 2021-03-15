class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W!=0)
            return false;
        map <int,int> m;
        
        for(int i:hand)
            m[i]++;
        
        for(auto [x,y]:m)
        {
            while(m[x]>=1)
            {
                for(int i=0;i<W;i++)
                {
                    if(m.count(x+i))
                        m[x+i]--;
                    else
                        return false;
                }
            }
        }
        return true;
        
    }
};