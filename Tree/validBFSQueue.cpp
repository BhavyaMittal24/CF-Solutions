#include<bits/stdc++.h>
using namespace std;;


int main(){
    int n;
    cin >> n;

    vector<set<int>> adj(n+1);

    for(int i = 0 ; i < n -1 ; i ++){
        int u, v;
        cin >> u >> v;

        adj[u].insert(v);
        adj[v].insert(u);
    }


    vector<int> bfs(n);

    for(int i = 0 ; i < n; i ++){
        cin >> bfs[i];
    }

    // check if the sequence is a valid bfs or not

    queue<int> q;

    bool isValid = true;
    int i = 0;
    q.push(1);
    i++;

    ////
    if(bfs[0] != 1) {
        cout << "No" << endl;
        return 0;
    }
    while( !q.empty() && i < n){

        int qSize = q.size();

        while(qSize--){
            int node = q.front();
            q.pop();
            int childrenCount = adj[node].size()-1;
            if(node == 1) childrenCount++;
            
            // for the given node, look if the next hchikdren elements in the bfs are present in its adj list
            while(childrenCount-- && i < n){
                if(adj[node].find(bfs[i]) == adj[node].end()) {
                    isValid = false;
                    break;
                }
                q.push(bfs[i]);
                i++;
            }
        }
    }

    if(isValid) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}