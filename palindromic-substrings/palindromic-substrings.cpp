class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        int ans=0;
        vector <vector <int>> dp(n,vector <int> (n,0));
        for(int i=n-1;i>=0;i--)
        {
          for(int j=i;j<n;j++)
          {
              dp[i][j]=s[i]==s[j]&&((j-i+1<=2)||dp[i+1][j-1]);
              ans+=dp[i][j];
          }
        }
        
        return ans;
    }
};