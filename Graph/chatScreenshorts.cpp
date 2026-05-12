#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n, k;
    cin >> n >> k;

    bool isCycle = false;
    
    vector<vector<int> > adj(n+1);

    for(int i = 0; i < k; i ++){
        int prev;
        for(int j = 0; j < n; j ++){
            
            int curr;
            cin >> curr;
            
            if(j == 0){
                continue;
            }

          
            if(j == 1){
                prev = curr;
                continue;
            }
            // directed graph
            adj[prev].push_back(curr);
            prev = curr;
        }
    }


    // check id a cycle exosts : 

    vector<int> indegree(n+1,0);

    for(int node = 1; node <=n; node ++){

        for( int x : adj[node]){
            indegree[x]++;
            // node -> x
        }
    }

    queue<int> q;
    for(int i = 1; i <=n; i ++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // indegree is 0 for each if these nodes
    vector<int> topo;

    while(!q.empty()){

        int node = q.front();
        q.pop();
    
        topo.push_back(node);
        for(int x: adj[node]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }


    if( topo.size() == n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}