#include<bits/stdc++.h>
using namespace std;

class DSU{

    public :
    vector<int> parent, size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i = 1 ;i <= n ; i ++){
            parent[i] = i;
        }
    }

    // log(n) on an average 
    int findSet(int x){
        if( x == parent[x]) return x;

        return parent[x] = findSet(parent[x]);
    }

    void unionSet(int a, int b){
        a = findSet(a);
        b = findSet(b);

        // a and b both belong to the same component
        if( a == b ){
            return;
        }
        if( size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
};


int main() {
    // ... (DSU, adj, permut, vis setup remains the same)

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    // permutation of nodesin which the yare removed
    vector<int> permut(n);

    for(int i = 0 ; i < n; i ++){
        cin >> permut[i];
    }

    vector<int> vis(n+1,0);

    vector<string> response;
    DSU dsu(n);;

    // FIX: Initialize with 0 nodes. If n > 0, the first node added 
    // is always connected (it's the only one).
    int cntOfNodesSoFar = 0;
    
    // FIX: A variable to track the maximum component size found so far.
    int maxComponentSize = 0; 
    
    // The main loop iterates backward, simulating adding nodes
    for (int i = n - 1; i >= 0; i--) {
        int node = permut[i];

        // Mark the node as "added" or "active"
        vis[node] = 1;
        cntOfNodesSoFar++;
        
        // When a node is added, its initial component size is 1.
        // Update maxComponentSize to be at least 1 (or the current size).
        maxComponentSize = max(maxComponentSize, 1);
        
        // Union the new node with its already 'active' neighbors
        for (int x : adj[node]) {
            if (vis[x]) {
                int rootA = dsu.findSet(node);
                int rootB = dsu.findSet(x);
                
                // Only union if they are in different sets
                if (rootA != rootB) {
                    dsu.unionSet(node, x);
                    // FIX: After a union, the new component size might be the largest.
                    // The new root is dsu.findSet(node) or dsu.findSet(x) - let's use node
                    maxComponentSize = max(maxComponentSize, dsu.size[dsu.findSet(node)]);
                }
            }
        }
        
        // The check for connectivity is done BEFORE the node is added back in this logic.
        // We push back the answer for the current state BEFORE node 'node' was added.
        // The original problem asks for connectivity *after* the current removal.
        // Since we are doing it in reverse, we check *after* the addition.
        
        // This check must happen *after* the connections have been established for 'node'.
        // We only add the result if we have at least one node added.
        if (cntOfNodesSoFar > 0) {
            if (maxComponentSize == cntOfNodesSoFar) {
                response.push_back("YES");
            } else {
                response.push_back("NO");
            }
        }
        
        // The last node added is needed for the first check of the original problem
        // which corresponds to the last iteration of the reversed process.
        // We will fix the indexing of the answer array below.
    }
    
    // The original logic missed the very first state (when 0 nodes are removed, i.e., all n nodes are present).
    // The loop iterates n times, producing n answers. The problem expects n+1 answers if it asks for the state
    // after each removal, *including* the state with all nodes present.
    // However, given your sample output size is 4 for N=4, let's stick to the n answers
    // produced by the reversed loop logic, and simply output them in the correct order.
    
    // The final loop state (when i=0) corresponds to the state where the last node (permut[0]) 
    // has just been added, and the response for that state is at the end of the `response` vector.
    
    // Output the results in the correct order (reversed again)
    for (int i = n-1 ; i >= 0 ; i--){
        cout << response[i] << endl;
    }
    
    return 0;
}