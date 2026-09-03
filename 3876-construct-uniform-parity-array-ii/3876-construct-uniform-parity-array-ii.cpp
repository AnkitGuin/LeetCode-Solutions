class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> od, ev;
        for(int i=0; i<n; i++){
            if(nums1[i]&1) od.push_back(nums1[i]);
            else ev.push_back(nums1[i]);
        }
        if(od.empty() || ev.empty()) return true;
        sort(od.begin(), od.end());
        sort(ev.begin(), ev.end());
        return (ev[0]>od[0]);
    }
};