class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map <int,vector <int>> m;
        for(int i=0;i<n;i++)
            m[arr[i]].push_back(i);
        queue <int> q;
        q.push(0);
        
        vector <bool> vis(n);
        vis[0]=true;
        int l=0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int i = q.front();
                q.pop();
                if(i==n-1)
                    return l;
                if(i-1>=0&&!vis[i-1])
                {
                    vis[i-1]=true;
                    q.push(i-1);
                }
                if(i+1<n&&!vis[i+1])
                {
                    vis[i+1] = true;
                    q.push(i+1);
                }
                for(int j:m[arr[i]])
                {
                    if(!vis[j])
                    {
                        q.push(j);
                        vis[j]=true;
                    }
                }
                m[arr[i]].clear();
            }
            l++;
        }
        
        return -1;
    }
};