class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=n;
        while(true){
            string s=to_string(ans);
            int num=1;
            for(char c: s) num*=(int)(c-'0');
            if(num%t==0) break;
            ans++;
        }
        return ans;
    }
};