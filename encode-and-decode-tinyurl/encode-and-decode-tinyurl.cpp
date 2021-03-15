class Solution {
public:
    int id=0;
    unordered_map <int,string> m1;
    unordered_map <string,int> m2;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m1[id]=longUrl;
        string shor="http://tinyurl.com/"+to_string(id);
        m2[shor]=id;
        id++;
        return shor;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m1[m2[shortUrl]];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));