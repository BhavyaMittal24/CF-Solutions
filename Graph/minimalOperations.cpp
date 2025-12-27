#include<bits/stdc++.h>
using namespace std;

// dfs is the human way of going through things : explorign all paths :
/// invlolves goign deep down as much acorss a  path as possible and then at a dead end go back and visit the other unvisited paths
void dfs( int node, vector<set<int>>& adj, vector<int> &vis){
    vis[node] = 1;
    for(int x : adj[node]){
        if( !vis[x]){
            dfs(x, adj, vis);
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector<string> passwords(n);

    for(int i = 0 ;i < n ; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        passwords[i] = s;
        // at most len is 50 : constant time : 50 operations max
       // sort(passwords[i].begin(), passwords[i].end());
    }

    // make an adj llist connecting all the nodes from 1 -> n
    vector<set<int>> adj(n+1);


    // form the adj list :
    // 26 *( n log50 + 50)
    for( int i = 0 ; i < 26 ; i++){
        vector<int> nodesContainingChar ;
        char letter = 'a' + i;

        //cout << i << " " << letter << endl;
        for(int p = 1 ; p <= n ; p ++){
            string pw = passwords[p-1];

            // lower bound returns an iterator : 
            auto idx = lower_bound(pw.begin(), pw.end(), letter);
            if(*idx == letter) {
                nodesContainingChar.push_back(p);
            }
        }


        for(int k = 1; k < nodesContainingChar.size(); k ++){
            int currNode = nodesContainingChar[k];
            int prevNode = nodesContainingChar[k-1];
            adj[currNode].insert(prevNode);
            adj[prevNode].insert(currNode);
        }
    }



    // find the number of connectee components

    vector<int> vis(n+1,0);

    int connectedComponents = 0;
    for(int i = 1; i <= n; i++){
        if( !vis[i]){
            dfs(i, adj, vis);
            connectedComponents ++;
        }
    }

    cout << connectedComponents << endl;
    return 0;
}