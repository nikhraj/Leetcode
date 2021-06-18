class NumArray {
public:
    vector <int> tree;
    vector <int> temp;
    int n;
    NumArray(vector<int>& nums) {
       // tree=nums;
        temp=nums;
        //for(int i:nums)
          //  tree.push_back(i);
        n=nums.size()+1;
        tree.resize(n);
        for(int i=0;i<n-1;i++)
        {
            add(i+1,nums[i]);
        }
        
    }
    
    void add(int i,int val)
    {
        //int n=tree.size();
        int j=i;
        while(j<n)
        {
            
            tree[j]+=val;
            j+=(j&-j);
        }
        
    }
    
    void update(int index, int val) {
        index++;
        int diff = val-temp[index-1];
        temp[index-1]=val;
        while(index<n)
        {
            tree[index]+=diff;
            index+=(index&-index);
        }
    }
    
    int getsum(int index)
    {
        int ans=0;
        index++;
        while(index>0)
        {
            ans+=tree[index];
            index-=(index&-index);
        }
        return ans;
    }
    
    
    int sumRange(int left, int right) {
       // cout<<getsum(right)<<endl;
       // for(int i:tree)
         //   cout<<i<<" ";
        //cout<<endl;
        return getsum(right)-getsum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */