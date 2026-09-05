class Solution {
public:
const int N=100000;
vector<int> spf=vector<int>(100001,0);
void sieve(){
    for(int i=0; i<=N; i++) spf[i]=i;
    for(int i=2; i*i<=N; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=N; j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
vector<pair<int,int>> pf(int x){
    vector<pair<int,int>> f;
    while(x>1){
        int p=spf[x], cnt=0;
        while(x%p==0){
            x/=p; cnt++;
        }
        f.push_back({p,cnt});
    }
    return f;
}
    int longestSubarray(vector<int>& nums, int k) {
        sieve();
        int n=nums.size();
        int l=0, r=0, len=0;
        map<int,int> mp;
        while(r<n){
            vector<pair<int,int>> cur=pf(nums[r]);
            for(auto [b,e]: cur){
                mp[b]++;
            }
            while(mp.size()>k){
                vector<pair<int,int>> rem=pf(nums[l]);
                for(auto [b,e]: rem){
                    mp[b]--;
                    if(mp[b]==0) mp.erase(b);
                }
                l++;
            }
            len=max(len, r-l+1);
            r++;
        }
        return len;
    }
};