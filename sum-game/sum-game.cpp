class Solution {
public:
    bool sumGame(string num) {
        //int c1=0,c2=0;
        float s1=0,s2=0;
        int n= num.size();
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?')
                s1+=4.5;
            else
                s1+=num[i]-'0';
        }
        
        for(int j=n/2;j<n;j++)
        {
            if(num[j]=='?')
                s2+=4.5;
            else
                s2+=num[j]-'0';
        }
       // cout<<s1<<" "<<s2<<endl;
        return s1!=s2;
    }
};