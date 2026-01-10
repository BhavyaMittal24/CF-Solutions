#include<bits/stdc++.h>
using namespace std;

vector<int> topo;
bool isCycle = false;

void dfs(int node, vector<int>& vis, vector<vector<int>> &adj){
    
    vis[node] = 1; // visited and in the current path

    for(int x : adj[node]){
        if( vis[x] == 0){
            dfs(x, vis, adj);
        }
        else if( vis[x] == 1 ) {
            isCycle = true;
        }
    }
    topo.push_back(node);
    vis[node]  = 2; // visited and processed
}

int main(){

    int n;
    cin >> n;
    
    // replace a-z with 1-26 : graph for 26 nodes

    // store the edges

    // for nodes from 1 to 26
    vector<vector<int>> adj(27);
    vector<string> names(n);

    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        names[i] = s;
    }

    for(int i = 1 ; i < n ; i ++){
        string s = names[i];
        string prevStr = names[i-1];

        int j = 0;

        int cntMismatch = 0;
        while( j < s.length() && j < prevStr.length() && cntMismatch == 0){
            if( s[j] == prevStr[j]){
                j++;
            }
            else {
                int prevNode = prevStr[j] - 'a' + 1;
                int currNode = s[j] - 'a' + 1;
                adj[prevNode].push_back(currNode);
                cntMismatch = 1;
            }
        }
        if(cntMismatch == 0) {
            if(prevStr.length() > s.length()) isCycle = true;
        }
    }

    // do a toposort
    vector<int> vis (27,0);
    for(int i = 1; i <= 26; i ++){
        if( isCycle) break;
        if( !vis[i]){
            dfs(i,vis, adj);
        }
    }

    reverse(topo.begin(), topo.end());

    if( isCycle) {
        cout << "Impossible" << endl;
        return 0;
    }

    for(auto node : topo){
        cout << char( node - 1 + 'a');
    }

    return 0;
}