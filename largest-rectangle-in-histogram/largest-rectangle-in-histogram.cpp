class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n=heights.size();
        stack <array<int,2>> st;
        int prev=0;
        int i;
        array <int,2> index;
        for(i=0;i<n;i++)
        {
            if(heights[i]>=prev)
                st.push({i,heights[i]});
            else
            {
                while(!st.empty()&&st.top()[1]>heights[i])
                {
                    index=st.top();
                    ans=max(ans,index[1]*(i-index[0]));
                    st.pop();
                }
                st.push({index[0],heights[i]});
            }
            
            prev=heights[i];
        }
        
        while(!st.empty())
        {
            index = st.top();
            st.pop();
            ans=max(ans,index[1]*(i-index[0]));
        }
        return ans;
    }
};