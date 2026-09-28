class Solution {
public:
    int maxDepth(string s) {
        int nestingD=0;
        int maxNest=0;
        set<char> nest;
        for(char it : s){
            if(it=='('){
            nestingD++;
            }
            if(it==')'){
            maxNest= max(maxNest,nestingD);
            nestingD--;
            }

        }
        return maxNest;
    }
};