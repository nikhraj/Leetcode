class Solution {
public:
    int m ,n;
    vector <vector <bool>> vis;
    vector <int> dirs = {0,-1,0,1,0};
    int helper(int ii,int jj,int i,int j,vector <vector <int>> &forest)
    {
        queue <pair<int,int>> q;
        q.push({ii,jj});
        vis[ii][jj]=1;
        int l=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto u=q.front();
                q.pop();
                if(u.first==i&&u.second==j)
                    return l;
                for(int k=1;k<5;k++)
                {
                    int pp=u.first+dirs[k-1];
                    int qq=u.second+dirs[k];
                    if(pp>=0&&pp<m&&qq>=0&&qq<n&&forest[pp][qq]!=0&&!vis[pp][qq])
                    {
                        q.push({pp,qq});
                        vis[pp][qq]=1;
                    }
                }
            }
            l++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        set <pair<int,array<int,2>>> v;
        m = forest.size();
        n = forest[0].size();
        if(forest[0][0]==0)
            return -1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(forest[i][j]>1)
                {
                    v.insert({forest[i][j],{i,j}});
                }
            }
        }
        // for(auto i:v)
        // {
        //     cout<<i.first<<" ";
        // }
       // queue <pair<int,int>> q;
       // auto it = v.begin();
        //auto some = *it;
        int ans = 0;
        array<int,2> prev = {0,0}; 
        //cout<<prev[0]<<" "<<prev[1]<<endl;
        
        //it++;
        auto it=v.begin();
        //q.push({it.second[0],it.second[1]});
        while(it!=v.end())
        {
            vis.clear();
            vis.resize(m,vector <bool> (n,false));
            auto some = *it;
            auto curr= some.second;
            //cout<<prev[0]<<" "<<prev[1]<<" "<<curr[0]<<" "<<curr[1]<<endl;
            int temp = helper(prev[0],prev[1],curr[0],curr[1],forest);
           // cout<<temp<<endl;
            if(temp==-1)
                return -1;
            ans+=temp;
            prev = curr;
            it++;
            
        }
        return ans;
        
    }
    
    
};