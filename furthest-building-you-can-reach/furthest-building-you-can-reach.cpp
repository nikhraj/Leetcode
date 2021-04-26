class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue <int,vector <int>> q;
        for(int i=0;i<h.size()-1;i++)
        {
            int d=h[i+1]-h[i];
            if(d>0)
            {
                q.push(-d);
            }
            if(q.size()>ladders)
            {
                bricks+=q.top();
                q.pop();
            }
            if(bricks<0)
                return i;
            
        }
        return h.size()-1;
    }
};