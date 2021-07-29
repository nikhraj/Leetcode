class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map <int,vector <int>> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]].push_back(i);
        }
        vector <bool> vis(n);
        queue <int> q;
        
        q.push(0);
        vis[0]=true;
        
        int l = 0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int i=q.front();
                q.pop();
                if(i==n-1)
                    return l;
                if(i+1<n&&!vis[i+1])
                {
                    vis[i+1]=true;
                    q.push(i+1);
                }
                if(i-1>=0&&!vis[i-1])
                {
                    vis[i-1]=true;
                    q.push(i-1);
                }
                for(int j:m[arr[i]])
                {
                    if(!vis[j])
                    {
                        vis[j]=true;
                        q.push(j);
                    }
                }
                m[arr[i]].clear();
            }
            l++;
                
        }
        
        return l;
        
        
    }
};