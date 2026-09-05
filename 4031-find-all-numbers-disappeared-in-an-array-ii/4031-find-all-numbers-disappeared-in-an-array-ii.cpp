class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int prev=lower-1;
        for(int x: nums){
            if(x<lower) continue;
            if(x>upper) break;
            if(x>prev+1) ans.push_back({prev+1, x-1});
            prev=x;
        }
        if(prev<upper) ans.push_back({prev+1,upper});
        return ans;
    }
};