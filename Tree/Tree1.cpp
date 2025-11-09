#include<bits/stdc++.h>
using namespace std;


// tree is a connected acyclic graph ; 
// a single unique path between 2 nodes eists
// can be hanfed from any one node

// Properties of a tree
// 1. It is connected acyclic graph
// 2. A single unique path exists between any 2 nodes in  tree
// 3. For a tree, you can reach from one node to all possible nodes : it is connected
// 4. No cycle, hence a single path exists between any two nodes
// 5. Neighours : set of adjacend nodes : directly connected : share an edge
// 6. degree : count of adjacent nodes : cnt of neightbours
// 7 Sum of degree for all nodes : summ deg(i) = 2*(n-1)
// 8. Each edge counts for deg +2                                  
// 9. FOr n nodes, no of edges are n-1                         
// 10. There only exists a single parent for each node.
// 11. We can convert any unrooted tree into a rooted tree, just pick up any node and hang the entire tree from there
// 12. Root 
// 13. Parent x : p(x) Second node in the path from x to the root .. Parent(root)  = -1
// 14. Ancestors (x) = set of all the nodes which come in the path from the node x to the root.
// 15. Descendants (x) = all nodes y where x is the ancestor ancestor(y) = x
// *16. Level of a node (x) : distance of node x from the root. Level (root) = 0 : used later on for calculating the distance
// 17. Height of a tree : Maximum level of a node : leaf node in a tree
// 18. Lowest common anestor : LCA(x,y)  : First common node which is in the path fom x to root and y to root
// 19. Paths in a tree : Up to a node, then down. NOT down and up 


void dfs(int curr, int parent, vector<vector<int>> adj, vector<int> &traversal){
    traversal.push_back(curr);

    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfs(neighbour,curr, adj, traversal);
        }
    }
}
int main(){
    int n;
    cin >> n;

    // 1 to n nodes
    // n-1 edges
    vector<vector<int>> adj(n+1);

    // Tc : is o(n) : in terms of edges : each edge : is climbed up once and went down once
    // adj list 
    // 1 -> 2,3,4
    // 2 -> 1, 5,6
    // 
// basically : no of functions calls is the set of all pais 1->2, 1->3, 1->4 
// 2->1 ,,, 
// basically each edge is seen through twice : ifparent the nskipped : 2 * edges
    vector<int> traversal;
    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,-1,adj,traversal);
    for(auto it : traversal) cout << it << " ";
    return 0;
}