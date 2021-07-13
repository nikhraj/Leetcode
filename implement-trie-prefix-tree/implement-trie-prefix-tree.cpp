class Trie {
public:
    /** Initialize your data structure here. */
    class TrieNode{
      public:
        vector <TrieNode *> next;
        bool isWord;
        TrieNode()
        {
            next.resize(26,NULL);
            isWord=false;
        }
        
    };
    
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for(char c:word){
            if(!p->next[c-'a'])
                p->next[c-'a']=new TrieNode();
            p=p->next[c-'a'];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p=root;
        for(char c:word){
            if(!p->next[c-'a'])
                return false;
            p=p->next[c-'a'];
        }
        return p->isWord;
    }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p=root;
        for(char c:prefix)
        {
            if(!p->next[c-'a'])
                return false;
            p=p->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */