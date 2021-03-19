class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector <bool> vis(n,0);
        
        queue <int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:rooms[u])
            {
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        for(bool i:vis)
            if(i==false)
                return false;
        return true;
    }
};