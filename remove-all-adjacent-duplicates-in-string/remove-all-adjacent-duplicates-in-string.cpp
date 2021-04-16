class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        st.push('#');
        for(int i=0;i<s.size();i++)
        {
            if(st.top()!=s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        string ans;
        while(st.size()>1)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};