class Solution {
public:
    void dfs(vector<int> &vis, vector<vector<int>> &adj, int u){
        vis[u]=1;
        for(auto v: adj[u]){
            if(!vis[v]) dfs(vis, adj,v);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invoc) {
        int m=invoc.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++) adj[invoc[i][0]].push_back(invoc[i][1]);
        vector<int> vis(n,0);
        dfs(vis,adj,k);
        bool ok=true;
        for(int i=0; i<m; i++){
            if(!vis[invoc[i][0]] && vis[invoc[i][1]]){
                ok=false; break;
            }
        }
        vector<int> ans;
        if(ok){
            for(int i=0; i<n; i++){
                if(!vis[i]) ans.push_back(i);
            }
            return ans;
        }
        vector<int> res(n,0);
        for(int i=0; i<n; i++) res[i]=i;
        return res;
    }
};