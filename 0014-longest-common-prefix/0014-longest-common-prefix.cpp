class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int mx=1e9;
        for(auto s: strs) mx=min(mx, (int)s.size());
        string ans="";
        string ss = strs[0];
        bool ok=true;
        for(int i=0; i<mx; i++){
            char c = ss[i];
            for(int j=1; j<n; j++){
                if(c!=strs[j][i]) ok=false;
            }  
            if(!ok) break;
            ans+=c;
        }
        return ans;
    }
};