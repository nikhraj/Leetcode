class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map <int,int> m;
        for(auto &i:wall)
        {
            int prev=0;
            for(auto &j:i)
            {
                j=j+prev;
                prev=j;
                m[j]++;
            }
        }
        int ans=INT_MAX;
        int target=*(wall[0].rbegin());
        for(auto [x,y]:m)
        {
            if(x!=target)
                ans=min(ans,n-y);
        }
        
        return ans==INT_MAX?n:ans;
        
    }
};