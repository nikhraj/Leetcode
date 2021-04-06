class Solution {
public:
    int minOperations(int n) {
        int index=n/2;
        return n&1?index*index+index:index*index;
    }
};