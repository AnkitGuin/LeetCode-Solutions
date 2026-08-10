class Solution {
public:
  
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        vector<int> sq;
        for(int i=1; i*i<=n; i++){
            dp[i*i]=1;
            sq.push_back(i*i);
        }
        for(int i=1; i<=n; i++){
            for(int s: sq){
                if(s>i) break;
                if(!dp[i-s]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return (dp[n]==1);
    }
};