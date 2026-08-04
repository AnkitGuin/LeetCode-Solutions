class Solution {
public:
    bool ok(vector<int> &nums, int key, int n){
        int l=0, r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key) return true;
            else if(nums[mid]<key) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=mn; i<=mx; i++){
            if(ok(nums,i,n)) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};