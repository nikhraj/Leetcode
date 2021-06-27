class Solution {
public:
    int fr,lr,fc,lc;
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
       
        
        fr = 0;
        lr = m-1;
        fc = 0;
        lc = n-1;
        while(fr<lr&&fc<lc)
        {
            int tempk=k;
            long long mod = (lr-fr+lc-fc)*2;
            tempk%=mod;
            for(int i=0;i<tempk;i++)
                rotatematrix(m,n,grid);
            fr++;
            fc++;
            lc--;
            lr--;
        }
        return grid;
        
    }
    void rotatematrix(int m,int n,vector <vector <int>> &grid)
    {
        
        //cout<<fr<<" "<<lr<<" "<<fc<<" "<<lc<<endl;
            int c1 = grid[fr][fc];
            int c2 = grid[lr][fc];
            int c3 = grid[lr][lc];
            int c4 = grid[fr][lc];

            for(int j=fc+1;j<=lc;j++)
            {
                grid[fr][j-1]=grid[fr][j];
            }

            for(int j=lc;j>=fc+1;j--)
            {
                grid[lr][j]=grid[lr][j-1];
            }

            for(int i=lr;i>=fr+1;i--)
            {
                grid[i][fc]=grid[i-1][fc];
            }
            grid[fr+1][fc]=c1;
            int i;
            for(i=fr;i<lr-1;i++)
            {
                grid[i][lc] = grid[i+1][lc];
            }
            grid[i][lc]=c3;
            
            

        
        
    }
    
};