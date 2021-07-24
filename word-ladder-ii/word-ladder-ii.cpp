class Solution {
public:
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map <string,int> m;
        for(string &s:wordList)
        {
            m[s]++;
        }
        
        vector <vector <string>> ans;
        if(!m.count(endWord))
            return ans;
        queue <vector <string>> q;
        q.push({beginWord});
        // set <string> vis;
        vector <string> words;
        // vis.insert(beginWord);
        if(!m.count(beginWord))
            m.erase(beginWord);
        bool f=false;
        while(!q.empty())
        {
            if(f)
                break;
            int s=q.size();
            words.clear();
            while(s--)
            {
                auto v=q.front();
                q.pop();
                
                string s=v.back();
                for(int j=0;j<s.size();j++)
                {
                    char c=s[j];
                    for(int i=0;i<26;i++)
                    {
                        char re = i+'a';
                        //cout<<re<<" ";
                        if(re!=c)
                        {
                            s[j] = re;
                            //cout<<s<<" ";
                            if(s==endWord)
                            {
                                f=true;
                                //cout<<1<<endl;
                                v.push_back(s);
                                ans.push_back(v);
                            }
                        
                            else if(m.count(s))
                            {
                                
                                //cout<<s<<" ";
                                //vis.insert(s);
                                auto temp = v;
                                // if(!vis.count(s))
                                // {
                                    words.push_back(s);
                                    temp.push_back(s);
                                    q.push(temp);
                                // }
                            }
                        }
                    }
                    s[j]=c;
                }
            }
            for(string s:words)
            {
                if(m.count(s))
                    m.erase(s);
            }
        }
            
        return ans;
    }
};