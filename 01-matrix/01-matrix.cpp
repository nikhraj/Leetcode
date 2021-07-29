class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        queue <array <int,2>> q;
        vector <int> dirs = {0,-1,0,1,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!nums[i][j])
                    q.push({i,j});
                else
                    nums[i][j]=INT_MAX;
            }
        }
        int l = 1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto p = q.front();
                q.pop();
                for(int k=1;k<5;k++)
                {
                    int i = p[0]+dirs[k-1];
                    int j = p[1]+dirs[k];
                    if(i>=0&&j>=0&&i<m&&j<n&&nums[i][j]==INT_MAX)
                    {
                        q.push({i,j});
                        //vis[i][j]=true;
                        nums[i][j]=l;
                    }
                }
            }
            l++;
        }
        
        return nums;
    }
};