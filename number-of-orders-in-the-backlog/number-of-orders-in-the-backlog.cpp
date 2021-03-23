class Solution {
public:
    int MOD=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& nums) {
        map <int,int> buy,sell;
        int ans=0;
        for(auto i:nums)
        {
            int x = i[0];
            int y = i[1];
            int z=i[2];
            if(z==1)
            {
                while(buy.size()>0&&buy.rbegin()->first>=x)
                {
                    y-=buy[buy.rbegin()->first];
                    if(y>0)
                        buy.erase(buy.rbegin()->first);
                    else
                    {
                        y+=buy[buy.rbegin()->first];
                        buy[buy.rbegin()->first]-=y;
                        y=0;
                        break;
                    }    
                }
                sell[x]+=y;
            }
            else
            {
                while(sell.size()>0&&sell.begin()->first<=x)
                {
                    y-=sell[sell.begin()->first];
                    if(y>0)
                        sell.erase(sell.begin()->first);
                    else
                    {
                        y+=sell[sell.begin()->first];
                        sell[sell.begin()->first]-=y;
                        y=0;
                        break;
                    }
                }
                buy[x]+=y;
            }
        }
        for(auto [x,y]:buy)
        {
            ans=(ans+y)%MOD;
        }
       // cout<<endl;
        for(auto [x,y]:sell)
        {
            ans=(ans+y)%MOD;
        }
        
        //cout<<endl;
        return ans;
    }
};