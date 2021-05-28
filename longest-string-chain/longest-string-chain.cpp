class Solution {
public:
    vector <int> len;
    vector <vector <int>> graph;
    
    int func(int u)
    {
        if(len[u]!=-1)
        {
            return len[u];
        }
        int ans=1;
        for(int v:graph[u])
        {
            ans=max(ans,func(v)+1);
        }
        return len[u]=ans;
    }
    
    
    int longestStrChain(vector<string>& words) {
        unordered_map <string,int> m;
        int n=words.size();
        len.resize(n,-1);
        graph.resize(n);
        for(int i=0;i<n;i++)
        {
            m[words[i]]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            string word = words[i];
            
            for(int j=0;j<word.size();j++)
            {
                string temp = word.substr(0,j)+word.substr(j+1);
                if(m.count(temp))
                {
                    graph[m[temp]].push_back(i);
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,func(i));
        }
        
        return ans;
        
    }
};