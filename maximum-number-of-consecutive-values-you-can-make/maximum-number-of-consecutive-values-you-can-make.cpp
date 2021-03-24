class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int maxi=1;
        //int sum=0;
        for(int i=0;i<coins.size()&&coins[i]<=maxi;i++)
        {
            maxi+=coins[i];
        }
        
        return maxi;
    }
};