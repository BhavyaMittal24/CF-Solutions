#include<bits/stdc++.h>
using namespace std;

int bfsCycle(int node, vector<vector<int>>& adj){

    queue<int> q;
    int n = adj.size();

    vector<int> vis(n,0);

    // node, parent
    q.push(node);
    
    vis[node] = 1;
    int cycleSize = -1;

    int dist = 1;

    while( !q.empty() && (cycleSize == -1)){

        int qSize = q.size();

        while( qSize  && (cycleSize == -1)){

            qSize --;
            int currNode = q.front();
            q.pop();

            for(int neighbour : adj[currNode]){
                if( !vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
                else if(neighbour == node){
                    cycleSize = dist;
                    break;
                }
            }
        }
        dist ++;
    }
    return cycleSize;
}

int main(){

    int n;
    cin >> n;

    // uni directed graph : directed graph

    vector<vector<int>> adj(n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int x;
            cin >> x;
            if(x) adj[i].push_back(j);
        }
    }

    // edge between i -> j
    vector<int> ans(n);

    for(int i = 0; i <n ; i++){
        int cycleLen = bfsCycle(i, adj);

        if( cycleLen != -1) {
            cout << cycleLen << endl;
        }
        else cout << "NO WAY" << endl;
    }

    return 0;
}