class Solution {
public:
    vector <vector <int>> ans;
    int n;
    void dfs(int node,vector <int> v,vector <vector <int>> &graph)
    {
        if(node==n-1)
        {
            ans.push_back(v);
            return;
        }
        
        for(int &i : graph[node])
        {
            auto v2=v;
            v2.push_back(i);
            dfs(i,v2,graph);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(0,{0},graph);
        return ans;
    }
};