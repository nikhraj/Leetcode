class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans = "";
        
        
        for(int i =0;i<n;i++)
        {
            if((k-1)>=26*(n-i-1))
            {
                ans+='a'+(k-1)%26;
                k-=k%26;
            }
            else
            {
                ans+='a';
                k--;
            }
        }
        
        return ans;
    }
};