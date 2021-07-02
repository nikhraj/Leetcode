class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>> q;
        
        for(auto i: arr)
        {
            q.push({abs(i-x),i});
        }
        vector  <int> ans;
        while(k--&&!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
  
    }
};