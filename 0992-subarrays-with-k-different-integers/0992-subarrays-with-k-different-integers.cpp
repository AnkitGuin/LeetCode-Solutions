class Solution {
public:

    int atmost(vector<int> &nums, int k, int n){
        int i=0, j=0;
        unordered_map<int,int> f;
        int ans=0;
        for(int j=0; j<n; j++){
            f[nums[j]]++;
            while(f.size()>k){
                f[nums[i]]--;
                if(f[nums[i]]==0) f.erase(nums[i]);
                i++;
            }
            int len=j-i+1;
            ans+=len;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmost(nums,k,n)-atmost(nums,k-1,n);
    }
};
