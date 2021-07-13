class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";
        stack<char> st;
        
        for(char c:num)
        {
            
            while(!st.empty()&&st.top()>c&&k)
            {
                st.pop();
                k--;
            }
            if(c!='0'||!st.empty())
            st.push(c);
        }
        string ans;
        
        while(k>0&&!st.empty())
        {
            st.pop();
            k--;
        }
        if(st.empty())
            return "0";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};