class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map <int,vector <int>> m;
        for(auto i:edges)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        
        for(auto [x,y]:m)
        {
            if(y.size()==edges.size())
                return x;
        }
        return -1;
    }
};