#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<set<int>> &adj, int &totalNodes, queue<int> &q, vector<int> &vis){
    totalNodes ++;

    for(int x : adj[curr]){
        if( x != parent) dfs(x, curr, adj, totalNodes,q,vis);
    }
    if(parent != 0 && adj[curr].size() == 1) {
        q.push(curr);
        vis[curr] = 1;
    }
}

void solve(){
    int n,k;
    cin >> n >> k;

    if(n == 1) {
        if( k >=1){
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
        return;
    }
    vector<set<int>> adj(n+1);

    int maxDegreeNode = 1;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        if(adj[maxDegreeNode].size() == 0 ){
            maxDegreeNode = u;
        }
        if(adj[maxDegreeNode].size() < adj[u].size()){
            maxDegreeNode = u;
        }
        if(adj[maxDegreeNode].size() < adj[v].size()){
            maxDegreeNode = v;
        }
    }

    // root at maxDegreeNode;
    int totalNodes = 0;
    queue<int> q;
    vector<int> vis(n+1,0);

    dfs(maxDegreeNode, 0, adj, totalNodes, q, vis);

    //cout << totalNodes << " " << maxDegreeNode << endl;
    int remNodes = totalNodes;
    int remSteps = k;
    while(!q.empty() && remSteps){
        int N = q.size();
        if( N == 1 && remNodes == 2){
            remSteps--;
            remNodes = 0;
            break;
        }  

        for(int i=0;i<N;i++){
            int leaf = q.front();
            q.pop();
            remNodes--;
            for(int x : adj[leaf]){
                if(!vis[x]){
                    adj[x].erase(leaf);
                    if(adj[x].size() == 1){
                        vis[x] = 1;
                        q.push(x);
                    }
                } 
            }
        }
        remSteps--;
    }
    cout << remNodes << endl;
}
int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}