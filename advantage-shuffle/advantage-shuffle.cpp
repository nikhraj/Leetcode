class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        vector <int> ans(n,-1);
        //unordered_map <int,int> m;
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++){
            
            auto it = upper_bound(A.begin(),A.end(),B[i]);
            int index = it-A.begin();
            
            //cout<<index<<" ";
            if(index<=A.size()-1)
            {
                ans[i]=A[index];
                A.erase(it);
            }
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
                ans[i]=A[j++];
        }
        return ans;
    }
};