class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
       // vector <int> dp(n,1);
        bool bit=true;
        int prev=nums[0];
        int c1=1;
        int c2=1;
        for(int i=1;i<nums.size();i++)
        {
            if(bit&&nums[i]>prev)
            {
                bit^=1;
                c1++;
            }
            else if(!bit&&nums[i]<prev)
            {
                bit^=1;
                c1++;
            }
            prev=nums[i];
        }
        prev=nums[0];
        bit=true;
        for(int i=1;i<nums.size();i++)
        {
            if(bit&&nums[i]<prev)
            {
                bit^=1;
                c2++;
               
            }
            else if(!bit&&nums[i]>prev)
            {
                bit^=1;
                c2++;
                //prev=nums[i];
            }
             prev=nums[i];
        }
        //cout<<c1<<" "<<c2<<" ";
        return max(c1,c2);
    }
};