class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return false;
            
        vector <bool> prime(n,true);
        int ans=0;
        for(int i=2;i*i<n;i++)
        {
            if(prime[i])
            {
                
                for(int j=i*i;j<n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++)
            ans+=prime[i];
        return ans;
        
    }
};