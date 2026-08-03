class Solution {
public:

    string stoneGameIII(vector<int>& sv) {
        int n=sv.size();
        string al="Alice"; string bo="Bob"; string t="Tie";
        vector<int> pref(n,0);
        pref[0]=sv[0];
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+sv[i];
        if(n==1){
            if(sv[0]>0) return al;
            if(sv[0]==0) return t;
            if(sv[0]<0) return bo;
        }
        vector<int> dp(n+3, 0);
        for(int i=n-1; i>=0; i--){
            dp[i]=-1e9;
            for(int j=i; j<min(n, i+3); j++){
                int sum;
                if(i==0) sum=pref[j];
                else sum=pref[j]-pref[i-1];
                dp[i]=max(dp[i], sum-dp[j+1]);
            }
        }
        if(dp[0]>0) return al;
        else if(dp[0]==0) return t;
        else return bo;
    }
};