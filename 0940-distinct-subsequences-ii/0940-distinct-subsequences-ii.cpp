class Solution {
public:
#define ll long long
#define MOD (ll)(1e9+7)

    int distinctSubseqII(string s) {
        ll n=s.size();
        vector<ll> f(26,0);
        ll ans=0;
        for(char ch: s){
            ll c=ch-'a';
            ll cnt=(ans+1)%MOD;
            ans=(ans+cnt-f[c])%MOD;
            if(ans<0) ans=(ans+MOD)%MOD;
            f[c]=cnt;
        }
        return (int)ans;
    }
}; 