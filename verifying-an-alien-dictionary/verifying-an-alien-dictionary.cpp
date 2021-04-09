class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector <int> m(26,0);
        for(int i=0;i<26;i++)
        {
            m[order[i]-'a']=i;
        }
        for(auto &word:words)
        {
            for(char &c:word)
            {
                c=m[c-'a']+'a';
            }
        }
        //for(auto &word:words)
          //  cout<<word<<endl;
        return is_sorted(words.begin(),words.end());
    }
};