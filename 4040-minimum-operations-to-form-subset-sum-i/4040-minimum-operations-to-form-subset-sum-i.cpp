class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<pair<int,int>>> val(n);
        for(int i=0; i<n; i++){
            vector<pair<int,int>> cur;
            int x=nums[i], c=0;
            while(x>0){
                cur.push_back({x,c});
                c++; x/=2;
            }
            x=2*nums[i], c=1;
            while(x<=sum){
                cur.push_back({x,c});
                c++; x*=2;
            }
            val[i]=cur;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,1e9));
        dp[0][0]=0;
        for(int i=1; i<=n; i++){
            for(int s=0; s<=sum; s++) dp[i][s]=dp[i-1][s];
            for(auto [x,cost]: val[i-1]){
                for(int s=x; s<=sum; s++){
                    if(dp[i-1][s-x]!=1e9){
                        dp[i][s]=min(dp[i][s], cost+dp[i-1][s-x]);
                    }
                }
            }
        }
        if(dp[n][sum]==1e9) return -1;
        return dp[n][sum];
    }
};