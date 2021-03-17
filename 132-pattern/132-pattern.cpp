class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector <int> mini(n);
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            mini[i]=min(nums[i],mini[i-1]);
        }
        stack <int> st;
        st.push(n-1);
        for(int j=n-2;j>=1;j--)
        {
            while(!st.empty()&&nums[j]>nums[st.top()])
            {
                if(nums[st.top()]>mini[j-1])
                    return true;
                st.pop();
            }
            st.push(j);
        }
        
        return false;
    }
};