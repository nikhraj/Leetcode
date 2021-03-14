class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Creating max heap -> {extraprofit,{passing_student, total_students}}
        priority_queue <pair <double,pair<int,int>>> q;
        
        double ans=0;
        for(auto c:classes)
        {
            q.push({profit(c[0],c[1]),{c[0]+1,c[1]+1}});
            ans+=double(c[0])/c[1];
        }
        
        // while we have extra students pop out profit to ans and add another pair
        while(extraStudents--)
        {
            auto [a,b]=q.top();
            q.pop();
            ans+=a;
            q.push({profit(b.first,b.second),{b.first+1,b.second+1}});
        }
        
        return ans/classes.size();
    }
    
    // Calculating profit difference by adding one student
    double profit(int a,int b)
    {
        return double(a+1)/(b+1)-double(a)/b;
    }
};