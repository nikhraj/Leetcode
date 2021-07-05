class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        int ans=INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        //vector <int> map(n);
       
        
        int sum=0;
        //s.insert(0);
        for(int k=0;k<m;k++)
        {
            vector <int> sums(n);
            for(int i=k;i<m;i++)
            {
                sum=0;
                set <int> s;
                s.insert(0);
                for(int j=0;j<n;j++)
                {
                    sums[j]+=matrix[i][j];
                    sum+=sums[j];
                    //cout<<sums[j]<<" "<<sum<<" ";
                    //cout<<sum<<" ";
                    auto it = s.lower_bound(sum-target);
                    if(it!=s.end())
                    {
                        //cout<<i<<" "<<j<<" "<<*it<<endl;
                        ans=max(ans,sum-*it);
                    }
                    s.insert(sum);
                }
                
            }
            //cout<<endl;
              //  cout<<endl;
        
        }
        return ans;
    }
};