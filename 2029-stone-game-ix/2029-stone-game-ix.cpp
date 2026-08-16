class Solution {
public:

    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int m0=0, m1=0, m2=0;
        for(int i=0; i<n; i++){
            if(stones[i]%3==0) m0++;
            else if(stones[i]%3==1) m1++;
            else m2++;
        }
        if(m0%2==0) return (m1>0 && m2>0);
        else return abs(m1-m2)>2;
    }
};