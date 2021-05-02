class WordFilter {
public:
    unordered_map <string,int> m;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                for(int k=s.size()-1;k>=0;k--)
                {
                    string prefix=s.substr(0,j+1);
                    string suffix=s.substr(k,s.size()-k+1);
                    m[suffix+'#'+prefix]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return m.count(suffix+'#'+prefix)?m[suffix+'#'+prefix]:-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */