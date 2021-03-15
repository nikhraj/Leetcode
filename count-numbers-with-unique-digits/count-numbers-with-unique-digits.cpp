class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        int digit=9;
        int ans=10;
        int temp=9;        
        n--;
        while(n--)
        {
            temp*=digit;
            ans+=temp;
            digit--;
        }
        
        return ans;
        
    }
};