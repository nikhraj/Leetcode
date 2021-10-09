class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map <int,int> m;
        int j=0;
        for(int &i:nums)
        {
            if(!m.count(i))
            {
                 m[i]++;
                swap(nums[j++],i);
               
            }
            
        }
        return j;
    }
};