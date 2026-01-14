#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

// Union by Rank
// Disjoint Set : when nodes belomg to differentt components
vector<int> parent;
vector<int> sz;

int findSet(int x){
    if(x == parent[x]) return x;

    // path compression : can also use a while loop to find the parent
    // int curr = x;
    // while( curr != parent[curr]){
    //     curr = parent[curr];
    // }
    return parent[x] = findSet(parent[x]);
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);

    if( u != v){
        // can only join in a certain manner : link sz[u] <= sz[v] smaller merges into large
        if(sz[u] < sz[v]){
            swap(u,v);
        }
        parent[v] = u;
        sz[u] += sz[v];
    }
}

bool isSameComponent(int u, int v){
    return findSet(u) == findSet(v);
}
//

// u,i { first, second }
// par[u][i] = {2^i th parent of u, max edge weight from u to 2^ith parent}
void dfs(int node, int parent, vector<vector<pair<int,int>>> &adj, vector<int> &level, vector<int> &edgeDist, vector<vector<pair<int,int>>> &par){

    if( parent != 0){
        level[node]  = level[parent] + 1; 
    }

    par[node][0] = {parent, edgeDist[node]};

    int m = par[0].size();
    // m = log2(n) + 1 : 2^m-1 = n
    for(int i = 1; i < m; i ++){

        int nextNode = par[node][i-1].first;
        int maxValueUptoNextNode = par[node][i-1].second;
        par[node][i] = { par[nextNode][i-1].first, max(maxValueUptoNextNode, par[nextNode][i-1].second) };
    }

    for(auto x : adj[node]){
        int v = x.first;
        int w = x.second;

        if( v != parent){
            edgeDist[v] = w;
            dfs(v, node, adj, level, edgeDist, par);
        }
    }
}

int findKthParent(int node, vector<vector<pair<int,int>>>& par, int k){

    int kthParent = node;
    int m = par[0].size() ;
    for(int i = 0; i < m ; i ++){
        if( k & (1 << i)) {
            kthParent = par[kthParent][i].first;
        }
    }
    return kthParent;
}


int maxEdgeValueInPath(int u, int v, vector<int> &level, vector<vector< pair<int,int>>> & par, vector<int> &edgeDist){

    if( u== v) {
        return INT_MIN;
    }

    int maxValue = INT_MIN;

    if( level[u] < level[v]){
        swap(u,v);
    }

    int diff = level[u] - level[v];

    int m = par[0].size();
    for(int i = 0; i < m ; i ++){
        if( diff & (1 << i)) {
            maxValue = max(maxValue, par[u][i].second);
            u = par[u][i].first;

        }
    }

    // finding the LCA for u and v when at the same level
    for(int i = m-1; i >= 0; i --){

        if(par[u][i] != par[v][i]){
            
            maxValue = max(maxValue, par[u][i].second);
            maxValue = max(maxValue, par[v][i].second);
            u = par[u][i].first;
            v = par[v][i].first;
        }
    }

    if( u == v) {
        return maxValue;
    }

    int LCA = par[u][0].first;

    maxValue = max(maxValue, edgeDist[u]);
    maxValue = max(maxValue, edgeDist[v]);
    return maxValue;
}

int main(){

    // form a mst

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);

    for(int i = 0; i < m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u,v,w};
    }

    // ElogE
    sort(edges.begin(), edges.end(), compare);

    sz.resize(n+1, 1);
    parent.resize(n+1, 0);

    for(int i = 1; i <= n; i ++){
        parent[i] = i;
    }

    // store n - 1 edges required to span the undirected graph : in the min possible cost
    vector<vector<pair<int,int>>> adj(n+1);

    // contains all the other edges which are not added in the mst
    vector<int> mstEdgesIndex;

    int mstSum = 0;
    for(int i = 0; i < m; i ++){

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if( isSameComponent(u,v)){
            mstEdgesIndex.push_back(i);
            continue;
        }

        unionSet(u,v);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        mstSum += w;
    }

    // we have all the edges which are not a part of the  : edge ei : u-> v
    // try adding each edge and then removing an edge in the path between u to v : remove the maximum edge in the path between u to v
    // mst value = old Value - MaxedgeReplaced (u,v) + edge(u,v);
    
    // root tree at 1;

    cout << "Sum for the Min Spanning tree " << mstSum << endl;

    vector<int> edgeDist(n+1,0);
    vector<int> level(n+1, 0);

    int maxPower = log2(n) + 1;

    vector<vector<pair<int,int>>> par (n+1, vector<pair<int,int>> (maxPower, {0, INT_MIN}));

    dfs(1, 0, adj, level, edgeDist, par);

    // try adding each non mst edge u,v,wtNew and replace it with it's weight and remove thr maximum largest weight in the path from u to v
    
    int secondMST = mstSum;
    for(auto edgeIdx : mstEdgesIndex){
        vector<int> edge = edges[edgeIdx];
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int maxEdgeInPath = maxEdgeValueInPath(u, v, level, par, edgeDist);
        secondMST = min( secondMST, mstSum + w - maxEdgeInPath);
    }

    cout << secondMST << "\n";

    return 0;
}