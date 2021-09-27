class Solution(object):
    def numUniqueEmails(self, emails):
        s = set()
        for email in emails:
            at = email.find('@')
            domain = email[at:]
            remain = email[:at]
            plus = remain.find('+')
            if plus!=-1:
                remain = remain[:plus]
            remain = remain.replace('.','')
            
            s.add(remain+'@'+domain)
        
        return len(s)
        
        
        