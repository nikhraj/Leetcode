class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //queue <int> q;
        
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int s=flowerbed.size();
        //for(int i:flowerbed)
           // cout<<i<<" ";
        for(int i=1;i<s-1;i++)
        {
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
            {
                n--;
                flowerbed[i]=1;
                
            }
               
        }
        return n<=0;
    }
};