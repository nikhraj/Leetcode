class Solution(object):
    def countSubstrings(self, s):
        ans=0
        for i in range(len(s)):
            for j in range(i,len(s)):
                temp=s[i:j+1]
                #print(temp)
                ans+=(temp==temp[::-1])
        return ans