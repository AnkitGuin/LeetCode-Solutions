class Solution {
public:
#define ll long long
    ll minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<ll> val(n);
        ll mx=0, sum=0;
        for(int i=0; i<n; i++) {
            val[i]=abs(nums1[i]-nums2[i]);
            sum+=val[i]; mx=max(mx, val[i]);
        }
        ll k=(ll)k1+k2;
        if(sum<=k) return 0;
        ll lo=0, hi=mx;
        while(lo<hi){
            ll mid=(lo+hi)/2;
            ll ops=0;
            for(ll x: val) ops+=max(0LL, x-mid);
            if(ops<=k) hi=mid;
            else lo=mid+1;
        }
        for(int i=0; i<n; i++){
            k-=max(0LL,val[i]-lo);
            val[i]=min(val[i], lo);
        }
        for(int i=0; i<n && k>0; i++){
            if(val[i]==lo){
                val[i]--;
                k--;
            }
        }
        ll ans=0;
        for(int i=0; i<n; i++) ans+=(val[i]*val[i]);
        return ans;
    }
};