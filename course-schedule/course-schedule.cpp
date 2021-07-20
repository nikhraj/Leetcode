class Solution {
public:
    bool canFinish(int n, vector<vector<int>>&nums) {
        vector <int> in(n);
        unordered_map  <int,vector <int>> m;
        for(auto &i:nums)
        {
            in[i[0]]++;
            m[i[1]].push_back(i[0]);
        }
        queue <int> q;
        
        for(int i=0;i<n;i++)
        {
            if(!in[i])
                q.push(i);
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            n--;
            for(int v:m[u])
            {
                if(--in[v]==0)
                    q.push(v);
            }
        }
        
        return n==0;
        
    }
};