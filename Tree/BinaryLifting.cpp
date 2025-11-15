#include<bits/stdc++.h>
using namespace std;

//nt N = 2e5+5;

//int M = 23;
int kthParent(int x, int k, vector<vector<int>> &parentMatrix){
    int curr = x;

    int m = parentMatrix[curr].size();

    // curretly i am going from LSB to MSB : can go from MSB to LSB as well
    // for(int i=0;i<m;i++){
    //     // ith bit is set
    //     if( (1 << i) & k) {
    //         curr = parentMatrix[curr][i];
    //     }
    // }
    // return curr;

    for(int i=m-1;i>=0;i--){
        // ith bit is set
        if( (1 << i) & k) {
            curr = parentMatrix[curr][i];
        }
    }
    return curr;
}

// Store in the binary lift

void dfs(int curr, int parent, vector<vector<int>> & parentMatrix, vector<vector<int>> &adj){
    parentMatrix[curr][0] = parent;

    int M = parentMatrix[curr].size();
    for(int i = 1; i <M;i++){
        parentMatrix[curr][i] = parentMatrix[parentMatrix[curr][i-1]][i-1];
    }

    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfs(neighbour, curr, parentMatrix, adj);
        }
    }
}

int main(){
    
    int n,q;
    cin >> n >> q;

    vector<int> parent(n+1,0);
    
    parent[1]=0;
    
    int M = log2(n)+1;
    vector<vector<int>> parentMatrix(n+1, vector<int> (20,0));
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++) {
        cin >> parent[i];
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);

    }

    dfs(1,0,parentMatrix, adj);
    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++){
        int x,k;
        cin >> x >> k;
        // node and the kth parent
        queries[i] = {x,k};
    }

    for(int i=0;i<q;i++){
        int x = queries[i].first;
        int k = queries[i].second;
        int ans = kthParent(x,k,parentMatrix);

        if(ans == 0){
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;

}