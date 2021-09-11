class LockingTree {
public:
    vector <int> status,pa;
    map <int,vector <int>> m;
    int n;
    LockingTree(vector<int>& parent) {
        n=parent.size();
        pa=parent;
        status.resize(n,-1);
        for(int i=1;i<n;i++)
        {
            m[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(status[num]!=-1)
            return false;
        status[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(status[num]==user)
        {
            status[num]=-1;
            return true;
        }
        
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(status[num]!=-1)
            return false;
        int p = pa[num];
        while(p!=-1)
        {
            if(status[p]!=-1)
                return false;
            p=pa[p];
        }
        
        queue <int> q;
        q.push(num);
        int c=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:m[u])
            {
                if(status[v]!=-1)
                {
                    c++;
                    status[v]=-1;
                }
                q.push(v);
            }
        }
        if(c==0)
            return false;
        status[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */