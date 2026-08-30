class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mndx=-1, mxdx=-1;
        int n=nums.size();
        int mx=-1e9, mn=1e9;
        for(int i=0; i<n; i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxdx=i+1;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mndx=i+1;
            }
        }
        int x1=min(mndx, mxdx);
        int x2=max(mndx, mxdx);
        int val1=x1+min(x2-x1, n-x2+1);
        int val2=(n-x2+1)+min(x2-x1, x1);
        return min(val1, val2);
    }
};