#include<bits/stdc++.h>
using namespace std;

int maxN = 2e5+1;
vector<int> order(maxN);

bool comp( int &a, int &b){

    return order[a] < order[b];
}
int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i=0; i < n-1; i ++){
        int u, v;

        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> bfs(n);
    for(int i=0; i< n; i ++){
        cin >> bfs[i];
        order[bfs[i]] = i;
    }

    if(order[1] != 0) {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 1 ; i <=n; i ++){
        sort(adj[i].begin(), adj[i].end(), comp);
    }

    // adj list sorted based on how they appear in the bfs

    vector<int> traversal;

    int i = 0;
    bool isValid = true;

    queue<int> q;
    vector<int> vis(n+1,0);
    q.push(1);

    while(!q.empty()){

        int node = q.front();
        q.pop();
        vis[node] = 1;

        traversal.push_back(node);
        if(node != bfs[i]){
            isValid = false;
            break;
        }
        i++;

        for(int x : adj[node]){
            if( !vis[x]){
                q.push(x);
            }
        }
    }

    if(isValid){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}