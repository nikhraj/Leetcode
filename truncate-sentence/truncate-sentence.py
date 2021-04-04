class Solution(object):
    def truncateSentence(self, s, k):
        strs=split(s)
        ans=''
        for i in range(k):
            ans+=strs[i]
            ans+=' '
        return ans.strip()
        