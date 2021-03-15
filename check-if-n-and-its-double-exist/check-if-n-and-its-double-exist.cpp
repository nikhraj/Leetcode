class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int,int> m;
        for(int i:arr)
        {
            m[i]++;
        }
        
        for(int i:arr)
        {
            if(i==0&&m[i]==1)
                continue;
            else if(!(i&1)&&m.find(i/2)!=m.end())
                return true;
        }
        
        return false;    
    }
};