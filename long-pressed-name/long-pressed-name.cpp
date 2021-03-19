class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m=name.size();
        int n=typed.size();
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(i<m&&name[i]==typed[j])
                i++;
            else if(!j||typed[j]!=typed[j-1])
                return false;
        }
        
        return i==m;
    }
};