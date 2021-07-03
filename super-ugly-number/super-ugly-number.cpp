class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       // priority_queue <int,set<int>,greater <int>> q;
        set <long> s;
        s.insert(1);
        int i=1;
        //int ans=1;
        while(i<n)
        {
            long num = *s.begin();
            s.erase(s.begin());
            //ans=num;
            
            //cout<<num<<" ";
            for(int j:primes)
            {
                s.insert(num*j);
            }
            i++;
        }
        return *s.begin();
    }
};