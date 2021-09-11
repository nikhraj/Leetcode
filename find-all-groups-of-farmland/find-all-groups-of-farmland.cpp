class Solution {
public:
    int m,n;
    int c=0;
    array <int,2> start,end;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector <vector <int>> ans;
        m=land.size();
        n=land[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j])
                {
                    start={INT_MAX,INT_MAX};
                    end={INT_MIN,INT_MIN};
                    dfs(i,j,land);
                    ans.push_back({start[0],start[1],end[0],end[1]});
                }
            }
        }
        
        
        
        return ans;
    }
    
    void dfs(int i,int j,vector <vector <int>> &land)
    {
        if(i<0||j<0||i>=m||j>=n||!land[i][j])
        {
            return;
        }
        land[i][j]=0;
        if(i<=start[0]&&j<=start[1])
        {
            start[0]=i;
            start[1]=j;
        }
        if(i>=end[0]&&j>=end[1])
        {
            end[0]=i;
            end[1]=j;
        }
        dfs(i-1,j,land);
        dfs(i+1,j,land);
        dfs(i,j-1,land);
        dfs(i,j+1,land);
    
    }
    
};