class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> vis(10001,0);
        for(int i=0; i<n; i++) vis[nums[i]]=1;
        int ans=-1;
        for(int x=k; x<=10000; x+=k){
            if(!vis[x]){
                ans=x; break;
            }
        }
        return ans;
    }
};