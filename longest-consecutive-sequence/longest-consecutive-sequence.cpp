class Solution {
public:
    int ans=0;
    unordered_map <int,int> m;
    vector <bool> vis;
    vector <int> len;
    int recur(int i)
    {
        int c=1;
        vis[m[i]]=1;
        if(m.count(i-1))
        {
            if(vis[m[i-1]])
            {
                c+=len[m[i-1]];
            }
            else
            {
                c+=recur(i-1);
            }

        }
        if(m.count(i+1))
        {
            if(vis[m[i+1]])
            {
                c+=len[m[i+1]];
            }
            else
            {
                c+=recur(i+1);
            }
        }
       
        len[m[i]]=c;
        ans=max(ans,c);
        return c;
    }
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        vis.resize(n);
        len.resize(n);
        for(int i=0;i<n;i++)
            m[nums[i]]=i;
        
        
        for(int &i:nums)
        {
            if(vis[m[i]])
                continue;
            recur(i);
            
        }
        return ans;
    }
};