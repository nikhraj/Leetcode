class Solution {
public:
    vector <vector <int>> ans;
    int m,n,c;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        m=nums.size();
        vector <vector <int>> ans2;
        if(m==0)
            return ans2;
        n=nums[0].size();
       
        ans.resize(m,vector <int> (n,0));
        for(int i=0;i<m;i++)
        {
            c=1;
            dfs(i,0,nums,INT_MIN);
            c=2;
            dfs(i,n-1,nums,INT_MIN);
        }
        for(int i=1;i<n;i++)
        {
            c=1;
            dfs(0,i,nums,INT_MIN);
        }
            
        for(int i=0;i<n-1;i++)
        {
            c=2;
            dfs(m-1,i,nums,INT_MIN);
        }
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]==3)
                    ans2.push_back({i,j});
            }
        }
        return ans2;
    }
    
    void dfs(int i,int j,vector <vector <int>> &nums,int prev)
    {
        if(i<0||j<0||i>=m||j>=n||ans[i][j]==c||ans[i][j]==3||nums[i][j]<prev)
            return;
        
        ans[i][j]+=c;

        prev=nums[i][j];
        dfs(i-1,j,nums,prev);
        dfs(i+1,j,nums,prev);
        dfs(i,j-1,nums,prev);
        dfs(i,j+1,nums,prev);
    }
    
};