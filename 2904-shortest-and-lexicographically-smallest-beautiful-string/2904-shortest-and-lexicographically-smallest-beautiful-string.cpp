class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<int> pref(n,0);
        pref[0]=(s[0]=='1');
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+(s[i]=='1');
        string ans="";
        int mx=n+1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int len=j-i+1;
                string x=s.substr(i,len);
                int ones=pref[j];
                if(i>0) ones-=pref[i-1];
                if(ones==k){
                    if((len<mx) || (len==mx && x<ans)){
                        ans=x;
                        mx=len;
                    }
                }
            }
        }
        return ans;
    }
};