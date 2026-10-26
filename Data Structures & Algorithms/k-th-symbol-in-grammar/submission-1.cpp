class Solution {
public:
    int kthGrammar(int n, int k) {
        int value=k-1,parity=0;
        while (value>0) { parity^=value&1; value>>=1; }
        return parity;
    }
};