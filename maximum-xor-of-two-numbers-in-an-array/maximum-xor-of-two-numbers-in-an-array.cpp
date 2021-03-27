class Solution {
public:
    class TrieNode{
        public:
        vector <TrieNode *> child;
        TrieNode()
        {
            child.resize(2,NULL);
        }
    };
    TrieNode *root;
    void insert(int val)
    {
        auto p=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(val>>i)&1;
            if(!p->child[bit])
                p->child[bit]=new TrieNode();
            p=p->child[bit];
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(int val:nums)
            insert(val);
        int ans=0;
        for(int val:nums)
        {
            int maxi=0;
            auto p=root;
            for(int i=31;i>=0;i--)
            {
                
                int bit=(val>>i)&1;
                if(p->child[bit^1])
                {
                    maxi+=(1<<i);
                    p=p->child[bit^1];
                }
                else
                    p=p->child[bit];
            }
            ans=max(ans,maxi);
        }
        return ans;
    }
};