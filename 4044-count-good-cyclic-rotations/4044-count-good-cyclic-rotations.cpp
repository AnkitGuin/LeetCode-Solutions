class Solution {
public:
#define ll long long
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        vector<ll> pref(n,0);
        pref[0]=nums[0];
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+nums[i];
        ll s1=pref[n/2-1], s2=pref[n-1]-pref[n/2-1];
        int ans=0;
        for(int i=0; i<n; i++){
            s1+=(nums[(i+n/2)%n]-nums[i]);
            s2+=(nums[i]-nums[(i+n/2)%n]);
            ans+=((s1-s2)>0);
        }
        return ans;
    }
};