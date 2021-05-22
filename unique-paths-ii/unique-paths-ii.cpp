class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        int first=nums[0][0];
        int prev=0;
        for(int i=0;i<m;i++)
        {
            if(nums[i][0]==1)
            {
                prev=1;
               // nums[i][0]=0;
            }
            if(prev)
            {
                nums[i][0]=0;
            }
            else
                nums[i][0]=1;
          //  cout<<nums[i][0]<<" ";
        }
        prev=first;
        for(int j=1;j<n;j++)
        {
            if(nums[0][j]==1)
            {
                prev=1;
                //nums[0][j]=0;
            }
            if(prev)
            {
                nums[0][j]=0;
            }
            else
                nums[0][j]=1;
            //cout<<nums[0][j]<<" ";
        }
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
               
                if(!nums[i][j])
                    nums[i][j]+=nums[i-1][j]+nums[i][j-1];
                else
                    nums[i][j]=0;
            }
        }
        
        return nums[m-1][n-1];
    }
};