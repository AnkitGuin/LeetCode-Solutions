class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int mx=0;
        int curr=0;
        for(char c: s){
            if(c=='(') mx=max(mx, ++curr);
            else if(c==')') --curr;
        }
        return mx;
    }
};