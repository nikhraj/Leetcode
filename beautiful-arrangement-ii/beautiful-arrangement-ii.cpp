class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector <int> ans;
        int i=1;
        int j=n;
        while(i<=j)
        {
            if(k>1)
            {
                ans.push_back(k--&1?i++:j--);
            }
            else
                ans.push_back(i++);
        }
        
        return ans;
    }
};