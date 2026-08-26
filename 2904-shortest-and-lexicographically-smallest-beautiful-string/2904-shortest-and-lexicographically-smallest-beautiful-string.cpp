class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int ones=0;
        string ans="";
        int mx=n+1;
        int i=0;
        for(int j=0; j<n; j++){
            if(s[j]=='1') ones++;
            while(ones>k){
                if(s[i]=='1') ones--;
                i++;
            }
            if(ones==k){
                while(s[i]=='0') i++;
                int len=j-i+1;
                string x=s.substr(i,len);
                if(len<mx || (len==mx && x<ans)){
                    mx=len;
                    ans=x;
                }
            }
        }
        return ans;
    }
};