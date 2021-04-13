class Solution {
public:
    int numTeams(vector<int>& rating) {
        set <int> left;
        set <int> right;
        int ans=0;
        int n=rating.size();
        for(int i=1;i<n;i++)
            right.insert(rating[i]);
        for(int i=1;i<n-1;i++)
        {
            left.insert(rating[i-1]);
            right.erase(right.find(rating[i]));
            auto it1=left.upper_bound(rating[i]);
            auto it2=right.upper_bound(rating[i]);
            int l1=distance(left.begin(),it1);
            int r1=left.size()-l1;
            int l2=distance(right.begin(),it2);
            int r2=right.size()-l2;
            ans+=l1*r2+l2*r1;
        }
        return ans;
    }
    
};