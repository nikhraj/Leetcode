class Solution {
public:
    bool validPalindrome(string s) {
        int ans=0;
        int i=0;
        int  j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
               // cout<<i<<" "<<j<<endl;
                string s1=s.substr(i+1,j-i);
                string temp=s1;
                //cout<<s1<<" ";
                reverse(s1.begin(),s1.end());
                if(s1==temp)
                {
                    return true;
                }
                string s2=s.substr(i,j-i);
                temp=s2;
                cout<<s2<<" ";
                reverse(s2.begin(),s2.end());
                return s2==temp;
            }
            i++;j--;
        }
        return true;
    }
};