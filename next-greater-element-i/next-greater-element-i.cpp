class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> m;
        for(int i=nums2.size()-1;i>=0;i--)
        {
           m[nums2[i]]=i;
        }
        vector <int> ans;
        
        for(int &i:nums1)
        {
            int index = m[i];
            int maxi = -1;
            for(int j=index;j<nums2.size();j++)
            {
                if(nums2[j]>i)
                {
                    maxi = nums2[j];
                    break;
                }
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
};