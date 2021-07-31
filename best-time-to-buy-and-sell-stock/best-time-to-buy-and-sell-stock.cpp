class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,prev=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            prev=min(prev,prices[i]);
            ans=max(ans,prices[i]-prev);
        }
        
        return ans;
    }
};