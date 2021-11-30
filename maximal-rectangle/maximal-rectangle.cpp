class Solution {
public:
    int ans;
    int m,n;
    int maximalRectangle(vector<vector<char>>& matrix) {
        //vector <int> height(n,0);
        m=matrix.size();
        if(m==0)
            return 0;
        n=matrix[0].size();
        if(n==0)
            return 0;
        //cout<<m<<" "<<n;
        vector <vector <int>> mat(m,vector <int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                   mat[i][j]=1;
            }
        }
        
        int temp=mat[0][0];
        ans=temp;
        for(int j=1;j<n;j++)
        {
            if(mat[0][j]==1)
            {
                if(mat[0][j-1]==1)
                    temp++;
                else
                    temp=1;
                ans=max(ans,temp);
            }
            else
                temp=0;
        }
        
        
        if(m==1)
        {
            return ans;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    mat[i][j]=mat[i-1][j]+1;
                }
               // cout<<mat[i][j]<<" ";
            } 
            //cout<<endl;
            helper(mat,i);
        }
        
        return ans;
        
    }
    void helper(vector <vector <int>> &matrix,int i)
    {
        stack <pair <int,int>> st;
        st.push({matrix[i][0],0});
        int prev=-1;
        int j;
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]>=prev)
            {
                st.push({matrix[i][j],j});
            }
            else
            {
                int index;
                while(!st.empty()&&matrix[i][j]<st.top().first)
                {
                    index=st.top().second;
                    ans=max(ans,(j-index)*(st.top().first));
                    st.pop();
                }
                st.push({matrix[i][j],index});
            }
            prev=matrix[i][j];
        }
        while(!st.empty())
        {
            ans=max(ans,(j-st.top().second)*(st.top().first));
            st.pop();
        }
    }
};