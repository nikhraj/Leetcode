class NumMatrix {
public:
    vector <vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        int a=matrix.size();
        int b=matrix[0].size();
        m.resize(a+1,vector <int> (b+1));
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                m[i][j]=m[i-1][j]+m[i][j-1]-m[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return m[r2+1][c2+1]-m[r1][c2+1]-m[r2+1][c1]+m[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */