class Solution(object):
    def selfDividingNumbers(self, left, right):
        ans=[]
        for i in range(left,right+1):
            f=True
            for j in str(i):
                if int(j)==0 or i%int(j)!=0:
                    f=False
                    break
            if f:        
                ans.append(i)
        return ans