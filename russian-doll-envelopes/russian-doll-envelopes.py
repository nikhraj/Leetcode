class Solution(object):
    def maxEnvelopes(self, nums):
        nums=sorted(nums,key=lambda i:(i[0],-i[1]))
        dp=[1 for i in range(len(nums))]
        for i in range(len(nums)):
            
            for j in range(i):
                if nums[i][1]>nums[j][1]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)
        
        
        
        
        