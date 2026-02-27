#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int node, int parent, vector<set<int>> &adj, vector<int> &vis){

    vis[node] = 1;

    for(int x : adj[node]){
       // each node has exactly 2 neighbours 
       if(x != parent){
            if(vis[x]) return true;
            if( isCyclic(x, node, adj, vis)) return true;
       }
    }
    return false;
}

void solve(){

    int n;
    cin >> n;

    // neighbours of i
    
    // 1 -> 2,2, 
    // we cna have multiple even same nodes in the adj list for a given node
    vector<set<int>> adj(n+1);

    for(int i = 1; i <= n ; i++){
        int v;
        cin >> v;
        // v is the neighbour of i
        adj[i].insert(v);
        adj[v].insert(i);
    }

    // min round dances : 1 + total cyclic components
    // max round dances : no of conecctected components
    // if all connected components are cyclic : then min round dances = max round dances

    int cyclicComponents = 0;
    int connectedComponents = 0;

    vector<int> vis(n+1, 0);
    for(int i = 1; i <=n ; i ++){
        
        if(!vis[i]){
            bool cyclic = isCyclic(i, -1, adj, vis);
            if(cyclic) cyclicComponents++;
            connectedComponents++;
        }
    }

    int minComp = (connectedComponents > cyclicComponents) ? 1 + cyclicComponents : cyclicComponents;
    
    cout << minComp << " " << connectedComponents << "\n";
    return;
 }

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}