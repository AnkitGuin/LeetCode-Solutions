class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        int ans=0;
        unordered_map<int,int> f;
        for(int j=0; j<n; j++){
            f[nums[j]]++;
            while(f[nums[j]]>k){
                f[nums[i]]--;
                i++; 
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};