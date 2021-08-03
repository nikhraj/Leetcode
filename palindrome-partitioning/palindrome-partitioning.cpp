class Solution {
public:
    bool ispalindrome(int i,int j,string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int n;
    vector <vector <string>> ans;
    void dfs(int init,vector <string> v,string s)
    {
        if(init==n)
        {
            ans.push_back(v);
            return;
        }
        for(int i=init;i<n;i++)
        {
            if(ispalindrome(init,i,s))
            {
                auto temp = v;
                temp.push_back(s.substr(init,i-init+1));
                dfs(i+1,temp,s);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        dfs(0,{},s);
        return ans;
    }
};