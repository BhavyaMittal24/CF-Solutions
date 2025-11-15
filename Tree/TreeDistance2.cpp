#include<bits/stdc++.h>
using namespace std;


void dfs(int curr, int parent, vector<vector<int>> adj, vector<int>& distance, long long & sum, vector<int> &subTree){
    if(parent == 0) distance[curr] = 0;
    else distance[curr] = distance[parent]+1;

    subTree[curr]  = 1;
    sum += 1ll*distance[curr];
    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            dfs(neighbour, curr, adj,distance,sum, subTree);
            subTree[curr] += subTree[neighbour];
        }
    }
}

void rerooting(int curr, int parent, vector<vector<int>> &adj, vector<long long> &sumDistances, vector<int> &subTree){
    
    long long n = subTree.size()-1;
    long long ans = 0;
    if(curr != 1) {
        ans = sumDistances[parent] - 2ll*subTree[curr];
        ans += n;
        sumDistances[curr] = ans;
    }

    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            rerooting(neighbour, curr, adj, sumDistances, subTree);
        }
    }
}


int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long sum = 0;
    vector<int> distance(n+1,0);
    vector<int> subTree(n+1,0);

    dfs(1,0,adj,distance, sum, subTree);

    vector<long long> sumDistances(n+1,0);
    sumDistances[1] = sum;

    rerooting(1,0, adj, sumDistances, subTree);

    for(int i=1;i<=n;i++){
        cout << sumDistances[i] << " " ;
    }
    return 0;
}