class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        priority_queue <array<int,3>,vector <array<int,3>>,greater <array<int,3>>> q;
        vector <vector <int>> ans;
        
        for(auto i:points)
        {
            q.push({(i[0]*i[0])+(i[1]*i[1]),i[0],i[1]});
        }
        
        while(!q.empty()&&K--)
        {
            auto p = q.top();
            q.pop();
            ans.push_back({p[1],p[2]});
        }
        
        return ans;
        
    }
};