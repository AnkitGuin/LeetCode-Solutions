class Solution {
public:

    int dp[105][205];
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> pref(n+1,0);
        for(int i=1; i<=n; i++) pref[i]=pref[i-1]+piles[i-1];
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                if((n-i)<=2*j){
                    dp[i][j]=pref[n]-pref[i];
                    continue;
                }  
                int dif=-1e9;
                for(int x=1; x<=2*j; x++){
                    dif=max(dif, pref[i+x]-pref[i]-dp[i+x][max(j,x)]);
                }
                dp[i][j]=dif;
            }   
        }
        return (dp[0][1]+pref[n])/2;
    }
};