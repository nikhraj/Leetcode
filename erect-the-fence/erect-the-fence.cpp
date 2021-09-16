class Solution {
public:
    
    int cmp(array <int,2> &p1,array <int,2> &p2,array <int,2> p3)
    {
        return (p3[1]-p2[1])*(p2[0]-p1[0])-(p2[1]-p1[1])*(p3[0]-p2[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector <vector <int>> ans;
        sort(trees.begin(),trees.end());
        
        deque <array <int,2>> upper,lower;
        
        for(auto &i:trees)
        {
            while(lower.size()>=2&&cmp(lower[lower.size()-2],lower[lower.size()-1],{i[0],i[1]})>0)
            {
                lower.pop_back();
            }
            while(upper.size()>=2&&cmp(upper[upper.size()-2],upper[upper.size()-1],{i[0],i[1]})<0)
            {
                upper.pop_back();
            }
            
            upper.push_back({i[0],i[1]});
            lower.push_back({i[0],i[1]});
        }
        set <array<int,2>> s;
        for(auto &i:upper)
        {
            s.insert(i);
        }
        
        for(auto &i:lower)
        {
            s.insert(i);
        }
        
        for(auto &i:s)
        {
            ans.push_back({i[0],i[1]});
        }
        
        return ans;
    }
};