#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<set<int>> adj(n+1);

    // no of edges in a tree is n-1
    // there exists atleast one cycle in a graph if each and every node has a degree of 2

    vector<int> childrenSize(n+1,-1);
    childrenSize[1] = 0;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        childrenSize[u]++;
        childrenSize[v]++;
    }

    // The tree is always rooted at 1 : always 

    // order[i] is the 
    vector<int> order(n);
    for(int i=0;i<n;i++){
        cin >> order[i];
        // order[i] is the index of the vertice in a tree
    }

    int i=0;
    int j=1;
    bool isValid = true;
    while(j < n){
        int children = childrenSize[order[i]];
        while(children--){
            // the next children elements don't contain any of the child of order[i];
            if( adj[order[i]].find(order[j]) == adj[order[i]].end() ) {
                isValid = false;
            }
            j++;
        }
        i++;
    }

    if(isValid){
        cout << "Yes\n";
    }

    else {
        cout << "No\n";
    }
    return 0;
}