class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // if(nums.size()==1)
        //     return 0;
        
        vector <int> temp = nums;
        
        sort(nums.begin(),nums.end());
        int i = 0,j=nums.size()-1;
        
        
        while((nums[i]==temp[i]||nums[j]==temp[j]))
        {
            if(i>=j)
                return 0;
            if(nums[i]==temp[i])
                i++;
            if(nums[j]==temp[j])
                j--;
            
        }
        
        return j-i+1;
        
    }
};