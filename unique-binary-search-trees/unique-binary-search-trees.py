import math

class Solution(object):
    def nCr(self,n,r):
        f = math.factorial
        return f(n) / f(r) / f(n-r)

    def numTrees(self, n):
        return self.nCr(2*n,n)/(n+1)
        """
        :type n: int
        :rtype: int
        """
        