class Solution {
public:
    int findTheWinner(int n, int k) {
        queue <int> q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        while(q.size()>1)
        {
            int t=k;
            while(--t>=1)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};