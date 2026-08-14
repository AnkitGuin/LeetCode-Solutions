#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:

#define ll long long

typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        ordered_set s;
        int ans=0;
        for(int i=n-1; i>=0; i--){
            ans+=s.order_of_key({nums[i],-1LL});
            s.insert({2LL*nums[i],i});
        }
        return ans;
    }
};