class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n=planks.size();
        map<int, int> cnt, res;
        for(int x: planks){
            cnt[x]++;
            res[x]++;
        }
        for(auto c1: cnt){
            for(auto c2: cnt){
                int a=c1.first, b=c2.first;
                if(a<b) res[a+b]+=min(cnt[a], cnt[b]);
                if(a==b) res[a+b]+=cnt[a]/2;
            }
        }
        int mx=0;
        for(auto k: res) mx=max(mx, k.second);
        return mx;
    }
};