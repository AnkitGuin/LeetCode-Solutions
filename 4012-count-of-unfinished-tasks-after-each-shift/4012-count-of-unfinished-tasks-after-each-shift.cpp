class Solution {
public:
#define ll long long
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<ll> pref(n,0);
        pref[0]=tasks[0];
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+tasks[i];
        vector<int> ans;
        ll done=0;
        for(int s: shifts){
            done+=s;
            if(done>=pref.back()){
                ans.push_back(0);
                done=0;
                continue;
            }
            auto it=lower_bound(pref.begin(),pref.end(),done);
            int idx=(int)(it-pref.begin());
            if(pref[idx]==done) ans.push_back(n-idx-1);
            else ans.push_back(n-idx);
            
        }
        return ans;

    }
};