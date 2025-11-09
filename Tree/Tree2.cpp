#include<bits/stdc++.h>
using namespace std;

void dfslevel(int curr, int parent, vector<vector<int>> adj, vector<int> &level){
   
    // getting information from the parent itself : parent -> child
    if(parent == -1) level[curr] = 0;
    else level[curr] = level[parent] +1;

    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfslevel(neighbour,curr, adj, level);
        }
    }
}

void dfsSize(int curr, int parent, vector<vector<int>> adj, vector<int> &size){
   
    size[curr] = 1;

    int sumOfChildren = 0;
    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfsSize(neighbour,curr, adj, size);
            sumOfChildren += size[neighbour];
        }
    }

    size[curr] += sumOfChildren;
}


// find the max distance of the farthest leaf node from a given node i : distance between i in a subtree where i is the root, 
void dfsLeafNodeDistance(int curr, int parent, vector<vector<int>> adj, vector<int> & maxLeafNodeDistance){
    // for any node i, it has children ci
    // maxLeafNideDIs = 1 + max ( dist from ci, cj, ...)
    // if leaf node ; 0

    maxLeafNodeDistance[curr] = 0;

    for(int neighbour : adj[curr]){
        if( neighbour == parent) continue;
        // dfs must happen, as answer of parent depends on children.
        dfsLeafNodeDistance(neighbour, curr, adj, maxLeafNodeDistance);
        maxLeafNodeDistance[curr] = max( maxLeafNodeDistance[curr], 1 + maxLeafNodeDistance[neighbour]);
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

    vector<int> level(n+1,0);
    vector<int> size(n+1,0);
    vector<int> maxLeafNodeDistance(n+1,0);

    // n edges : total are 2*(n-1) but we input only n-1 1->2 and 2->1 are same eseentially
    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // infp fro parent to child : or from child to parent
    dfslevel(1,-1,adj,level);
    dfsSize(1,-1,adj, size);
    dfsLeafNodeDistance(1,-1,adj, maxLeafNodeDistance);
    for(auto it : level) cout << it << " ";
    cout << endl;

    for(auto it : size ) cout << it << " ";
    cout << endl;

    for(auto it : maxLeafNodeDistance) cout << it <<" ";
    cout << endl;
    return 0;
}