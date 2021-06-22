class Solution(object):
    def reorderLogFiles(self, logs):
        digits = []
        letters = []
        for log in logs:
            strs = log.split()
            if strs[1].isdigit():
                digits.append(log)
            else:
                letters.append((' '.join(strs[1:]),strs[0]))
        letters = sorted(letters)
        ans = []
        for i in letters:
            ans.append(i[1]+' '+i[0])
        ans.extend(digits)
        
        return ans
        
        