class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        auto mini = *min_element(strs.begin(),strs.end(),[](string s1,string s2){return s1.size()<s2.size();});
        //cout<<mini<<endl;
        
        string ans = "";
        bool f=false;
        for(int i=0;i<mini.size();i++)
        {
            char prev = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=prev)
                {
                    
                    f=true;
                    break;
                }
            }
            if(f)
                break;
            else
            ans+=prev;
        }
        
        
        return ans;
        
        
     
        
    }
};