class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector <vector <int>> m(26);
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        for(auto s1:words)
        {
            bool f=true;
            int prev=-1;
            vector <int> curr(26,0);
            if(s1.size()>s.size())
                continue;
            for(char c:s1)
            {
                int index = c-'a';
                
                while(curr[index]<m[index].size()&&m[index][curr[index]]<=prev)
                {
                    curr[index]++;
                }
                if(curr[index]==m[index].size())
                {
                    f=false;
                    break;  
                }
                prev=m[index][curr[index]];
               // curr[index]++;
            }
            if(f)
            {
               // cout<<s1<<endl;
                ans++;
            }
        }
        
        return ans;
        
    }
};