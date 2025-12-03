#include<bits/stdc++.h>
using namespace std;

int main(){

    // given a graph and its bfs, you need to check if it is vslid or not
    // for each node, it's children are inserted in any random order from the adjacency list

    // 1 -> 2, 3, 4 : 1 3 4 2 
    // 3 -> 5 ,6 7
    // 

    int n, m;
    cin >> n >> m;

    vector<int> bfs(n);

   
    vector<set<int>> adj(n+1);

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i = 0 ;i < n ;i ++) cin >> bfs[i];

    // 0 (m * logn)

    vector<int> vis(n+1,0);

    queue<int> q;
    vis[1] = 1;
    q.push(1);

    if( bfs[0] != 1) {
        cout << "No" << endl;
        return 0;
    }
    int i = 1;

    bool isValid = true;
    while(!q.empty()){

        int qSize = q.size();
        // for each level :
        for(int  j = 0 ; j < qSize; j++){

            int node = q.front();
            q.pop();

            // coutn the children I should be able to see next which are not visited yet 
            int children = 0;
            for(int x : adj[node]){
                if( vis[x] == 0){
                    children++;
                } 
            }

            while(children--){
                int currNode = bfs[i];
                if( adj[node].find(currNode) == adj[node].end() || vis[currNode] == 1){
                    isValid = false;
                    break;
                }
                
                q.push(currNode);
                vis[currNode] = 1;
                i++;
            }

        }
    }

    if(isValid) {
        cout << "Yes" << endl;
    }

    else {
        cout << "No" << endl;
    }
    return 0;
}