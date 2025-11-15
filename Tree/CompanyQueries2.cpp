#include<bits/stdc++.h>
using namespace std;

int kthParent(int x, int k,  vector<vector<int>> &parentMatrix){

    int curr = x;
    int m = parentMatrix[curr].size();

    for(int i=0;i<m;i++){
        if (( 1 << i) & k ){
            curr = parentMatrix[curr][i];
        }
    }
    return curr;
}


int findLCABinarySearch(int x, int y, vector<int> &level, vector<vector<int>> &parentMatrix){

    if(level[y] > level[x]){
        swap(x,y);
    }

    int diff = level[x] - level[y];

    // find kth parent for x
    int m = parentMatrix[x].size();

    x = kthParent(x,diff,parentMatrix);
    // both are at same level

    if(x == y) return x;

    // k from 1 to n level[x] are the possible common ancestors

    int LCA = 1;
    int mid = 0;
    int low = 1;
    int high = level[x];

    while( low <= high){
        
        mid = (low + high)/2;
        int kx = kthParent(x, mid,parentMatrix);
        int ky = kthParent(y, mid, parentMatrix);
        if(ky ==kx){
            LCA = kx;
            high= mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return LCA;
    
}
// TC : is o(m + m)
int findLCA(int x, int y, vector<int> &level, vector<vector<int>> &parentMatrix){

    // we assume that x is always below
    if(level[y] > level[x]){
        swap(x,y);
    }

    int diff = level[x] - level[y];

    // find kth parent for x
    int m = parentMatrix[x].size();

    for(int i=0;i<m;i++){
        if( (1 << i) & diff){
            x = parentMatrix[x][i];
        }
    }
    
    // both are at same level

    if(x == y) return x;

    for(int i = m-1;i>=0;i--){
        if( parentMatrix[x][i] != parentMatrix[y][i]){
            x = parentMatrix[x][i];
            y = parentMatrix[y][i];
        }
    }

    return parentMatrix[x][0];
}


// given q queries, for each query , you need to find the LCA (a,b) 

void dfs(int curr, int parent, vector<vector<int>> &adj, vector<vector<int>> &parentMatrix, vector<int> &level){
    
    if(curr != 1) level[curr] = level[parent]+1;

    parentMatrix[curr][0] = parent;
    int m = parentMatrix[curr].size();
    for(int i=1;i<m;i++){
        parentMatrix[curr][i] = parentMatrix[parentMatrix[curr][i-1]][i-1];
    }

    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfs(neighbour, curr, adj, parentMatrix, level);
        }
    }
}

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> parent(n+1,0);
    parent[1] = 0;


    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
        cin >> parent[i];
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }

    int m = log2(n) + 1;
    // this is the maximum bit or max power of parent that we can have  
    
    vector<vector<int>> parentMatrix(n+1, vector<int>(m,0));

    vector<pair<int,int>> queries(q);

    // for the LCA : if two nodes are at the same level, then LCA should also be the common kth parent for both the nodes
    // distance from the root node 

    vector<int> level(n+1,0);

    dfs(1,0,adj, parentMatrix, level);
    for(int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        queries[i] = {x,y};
    }

    for(int i=0;i<q;i++){
        int x = queries[i].first;
        int y = queries[i].second;

        int ans = findLCABinarySearch(x,y,level, parentMatrix);
        cout << ans << endl;
    }
    return 0;
}