class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
       int n=dist.size();
        vector <vector <int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({(dist[i]/speed[i])+((dist[i]%speed[i])>0),i});
        }
        sort(v.begin(),v.end(),[](vector <int> &a,vector <int>&b){
            return a[0]<b[0];
        });
        
        int ans=1;
        for(int i=1;i<n;i++)
        {
            //cout<<v[i][0] <<" "<<v[i][1]<<endl;
            if((dist[v[i][1]]-(i*speed[v[i][1]]))<=0)
                return ans;
            ans++;
        }
        
        return ans;
        
    }
};