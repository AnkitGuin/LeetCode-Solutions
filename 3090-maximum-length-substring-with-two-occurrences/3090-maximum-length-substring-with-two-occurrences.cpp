class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        int i=0, j=0;
        unordered_map<char,int> f;
        for(int j=0; j<n; j++){
            f[s[j]]++;
            while(f[s[j]]>2){
                f[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};