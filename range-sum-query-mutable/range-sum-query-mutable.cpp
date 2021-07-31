class NumArray {
public:
    int n;
    vector <int> tree;
    vector <int> num;
    NumArray(vector<int>& nums) {
        num=nums;
        n=nums.size();
        tree.resize(n+1);
        //tree=nums;
        for(int i=1;i<=n;i++)
        {
            int val=nums[i-1];
            int j=i;
            while(j<=n)
            {
                tree[j]+=val;
                j+=(j&-j);  
            }
        }
        // for(int i:tree)
        //     cout<<i<<" ";
    }
    
    void update(int index, int val) {
        int diff = val-num[index];
        index++;
        int j=index;
        while(j<=n)
        {
            tree[j]+=diff;
            j+=(j&-j);
        }
        num[index-1]=val;
    }
    
    int sumRange(int left, int right) {
        
        return sum(right+1)-sum(left);
    }
    
    int sum(int index)
    {
        int su=0;
        int j=index;
        while(j>0)
        {
            su+=tree[j];
            j-=(j&-j);
        }
        return su;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */