class Solution {
public:
    unordered_map <int,vector <int>> m;
    vector <int> ans;
    vector <int> dfs(int u,int parent,vector <int> ma,string &labels)
    { 
        for(int v:m[u])
        {
            if(v==parent)
                continue;
            vector <int> ans1(26);
            vector <int> temp(26,0);
            temp[labels[v]-'a']++;
            ans1=dfs(v,u,temp,labels);
            for(int i=0;i<26;i++)
            {
                ma[i]+=ans1[i];
            }
        }
        ans[u]=ma[labels[u]-'a'];
        return ma;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        for(auto i:edges)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector <int> ma(26,0);
        ma[labels[0]-'a']++;
        dfs(0,-1,ma,labels);
        return ans;
    }
};