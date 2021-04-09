class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector <int> ans;
        vector <vector <int>> m(n);
        vector <int> deg(n,0);
        for(auto i:edges)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;
        }
        queue <int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
                q.push(i);
        }
        if(!q.size())
            return {0};
        while(n>2)
        {
            int s=q.size();
            n-=s;
            while(s--)
            {
                int u=q.front();
                q.pop();
                for(int v:m[u])
                {
                    if(--deg[v]==1)
                        q.push(v);
                }
            }
            
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};