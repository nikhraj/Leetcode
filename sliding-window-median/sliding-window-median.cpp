class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector <double> ans;
        int n=nums.size();
        multiset <int> s;
        int i1,i2;
        if(k&1)
        {
            i1=k/2;
            i2=i1;
        }
        else
        {
            i1=k/2-1;
            i2=i1+1;
        }
        
        int r=0;
        for(r=0;r<k;r++)
        {
            s.insert(nums[r]);
        }
        auto it1 = next(s.begin(), i1);
        auto it2 = next(s.begin(), i2);
        ans.push_back((double(*(it1))+double(*(it2)))/2);
        int l=0;
        //cout<<i1<<" "<<i2<<endl;
        while(r<n)
        {
            
            s.erase(s.find(nums[l]));
            s.insert(nums[r]);
            it1 = next(s.begin(), i1);
            it2 = next(s.begin(), i2);
            ans.push_back((double(*(it1))+double(*(it2)))/2); 
            r++;
            l++;
        }
        
        return ans;
        
    }
};