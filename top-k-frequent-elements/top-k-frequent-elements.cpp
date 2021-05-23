class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        unordered_map <int,int> m;
        
        for(int i:nums)
        {
            m[i]++;
        }
        
        multiset <pair<int,int>,greater<pair<int,int>>> s;
        for(auto [x,y]:m)
        {
            s.insert({y,x});
        }
        
        while(k)
        {
            auto temp=*s.begin();
            ans.push_back(temp.second);
            s.erase(s.begin());
            k--;
        }
        
        return ans;
        
    }
};