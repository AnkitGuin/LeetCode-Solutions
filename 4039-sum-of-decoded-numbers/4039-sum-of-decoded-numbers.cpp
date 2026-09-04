class Solution {
public:
#define ll long long
    ll mpow(ll b, ll e, ll mod){
        ll res=1;
        b%=mod;
        while(e>0){
            if(e&1) res=(res*b)%mod;
            b=(b*b)%mod;
            e>>=1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        ll mod=1e9+7;
        ll ans=0;
        for(int i=0; i<n; i++){
            ll w=nums[i]%10;
            ll d=nums[i]/10;
            string s=to_string(d);
            int len=s.size();
            string x=s.substr(0,w);
            string y=s.substr(w);
            ll nx=stoll(x); ll ny=stoll(y);
            ll val=mpow(nx,ny,mod);
            ans+=val;
            ans%=mod;
        }
        return ans;
    }
};