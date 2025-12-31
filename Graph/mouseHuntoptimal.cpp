#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int posn[N];

void dfs(int node, vector<int> &vis, vector<int> &a, int & minValue, vector<int> &pathVis, vector<int> &cost){

    // in the path and visited as well
    vis[node] = 1;

    // inside the path
    pathVis.push_back(node);

    int nextNode = a[node];

    if(!vis[nextNode]){
        dfs(nextNode, vis, a, minValue, pathVis, cost);
    }

    else if( vis[nextNode] == 1){

        auto it = find(pathVis.begin(), pathVis.end(), nextNode);

        while( it != pathVis.end()){
            int x = *it;
            minValue = min( minValue, cost[x]);
            it++;
        }
    }

    // these nodes are processed and marked
    vis[node]  = 2;
    pathVis.pop_back();
}

// approach 2 : find the cyclic Node and then at a later stage find it's path


// use the posn
void dfs2(int node, vector<int> &vis, vector<int> &a, int & minValue, vector<int> &pathVis, vector<int> &cost){

    // in the path and visited as well
    vis[node] = 1;

    // inside the path
    pathVis.push_back(node);

    posn[node] = pathVis.size() -1;
    
    int nextNode = a[node];

    if(!vis[nextNode]){
        dfs(nextNode, vis, a, minValue, pathVis, cost);
    }

    else if( vis[nextNode] == 1){
        // posn[nextNode ] : stores the index in the pathVis array
       int idxCyclicNode = posn[nextNode];

       // we aim to find the cylcic path from the node which has vis[x] = 2 : for this reason we use the pathVis array
       for( int i = idxCyclicNode; i < pathVis.size() ; i++){
          minValue = min( minValue, cost[pathVis[i]]);
       }
    }

    // these nodes are processed and marked : it's very important for these nodes to be set and to be marked as not in the path
    vis[node]  = 2;
    // node is removed from stack,marked as in state 2 : which is prcoceesed and NOT in the path now.
    pathVis.pop_back();
}


// backtrack the cyclic path using a parent array

void dfs3 ( int node, vector<int> &vis, vector<int> &a, vector<int> &cost, vector<int> &parent, int & minValue){

    vis[node] = 1;
    
    int nextNode = a[node];

    if( vis[nextNode] == 0){
        parent[nextNode] = node;
        dfs3( nextNode, vis, a, cost, parent, minValue);
    }
    
    // the nextNode is still in the stack : in the path visited array
    else if( vis[nextNode] == 1 ){

        minValue = min(minValue, cost[nextNode]);

        int curr = node;

        while( curr != nextNode){
            minValue = min(minValue, cost[curr]);
            curr = parent[curr];
        }
    }

    // set the node visited to be processed and will not be viisted again
    vis[node] = 2;
}
int main(){

    int n ;
    cin >> n;

    memset(posn, 0, sizeof(posn));

    vector<int> cost(n+1, 0);
    vector<int> a(n+1, 0);

    for(int i = 1; i <= n; i ++){
        cin >> cost[i];
    }

    for(int i = 1; i <=n ; i ++){
        cin >> a[i];
    }

    vector<int> vis(n+1, 0);

    long long totalCost = 0;

    for(int i = 1; i <= n; i ++){
        // we traevrse a set of reachable nodes from i : and check if they have a cycle
        if( vis[i] == 0){
            vector<int> pathVis;
            int minValue = INT_MAX;
            // each cc has one cycle : find the min value for this cycle
            // df1
            // dfs2(i, vis, a, minValue, pathVis, cost);

            vector<int> parent(n+1, 0);

            dfs3(i, vis, a, cost, parent, minValue);

            // if we visit only the cycle which has already been reached, then the minValue won;t b changed
            if( minValue != INT_MAX) totalCost += minValue;
        }
    }

    cout << totalCost << endl;
    return 0;
}