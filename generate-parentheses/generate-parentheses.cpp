class Solution {
public:
    int size;
    vector <string> ans;
    vector<string> generateParenthesis(int n) {
        size=n;
        func("",0,0);
        return ans;
    }
    
    void func(string s,int m,int n)
    {
        if(m<n||s.size()>(size*2))
        {
            return;
        }
        
        if(m==size && n==size)
        {
            ans.push_back(s);
            return;
        }
        
        func(s+'(',m+1,n);
        func(s+')',m,n+1);
        
    }
    
};