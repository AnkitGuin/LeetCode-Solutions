class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xo=0, c0=0;
        for(int i=0; i<n; i++){
            xo^=nums[i];
            c0+=(nums[i]==0);
        }
        if(c0==n) return 0;
        if(xo==0) return (n-1);
        else return n;
    }
};