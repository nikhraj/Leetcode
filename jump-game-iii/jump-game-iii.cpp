class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int  n = arr.size();
        vector <bool> vis(n,false);  
        queue <int> q;
        
        q.push(start);
        vis[start] = true;
        
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            if(arr[i]==0)
                return true;
            int ii =i+arr[i];
            int jj = i-arr[i];
            if(ii<n&&!vis[ii])
            {
                vis[ii]=true;
                q.push(ii);
            }
            if(jj>=0&&!vis[jj])
            {
                vis[jj]=true;
                q.push(jj);
            }
                
        }
    
        return false;
    }
};