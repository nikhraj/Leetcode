class LRUCache {
public:
    int s;
    list <int> l;
    unordered_map <int,pair<int,list <int>::iterator>> m;
    LRUCache(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        if(!m.count(key))
        {
            return -1;
        }
        l.erase(m[key].second);
        l.push_front(key);
        m[key].second = l.begin();
        return m[key].first;
        
    }
    
    void put(int key, int value) {
        if(m.count(key))
        {
            m[key].first=value;
            l.erase(m[key].second);
            l.push_front(key);
            m[key].second = l.begin();
        }
        else
        {
            if(l.size()==s)
            {
                auto it = l.end();
                it--;
                m.erase(m.find(*it));
                l.erase(it);
            }
            l.push_front(key);
            m[key]={value,l.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */