class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int pro=1, sum=0;
        for(char c: s){
            pro*=(int)(c-'0');
            sum+=(int)(c-'0');
        }
        int res=pro+sum;
        return (n%res==0);
    }
};