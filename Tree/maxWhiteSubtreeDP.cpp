#include<bits/stdc++.h>
using namespace std;

int N = 2e5+1;
vector<int> maxVal(N,0);

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> & maxSubTree, vector<int> &color,  vector<set<int>> &goodNeighbours){

    maxSubTree[node] = color[node];

    for(int children : adj[node]){
        if( children != parent){
            int oldValue = maxSubTree[node];

            dfs(children, node, adj, maxSubTree, color, goodNeighbours);

            if( oldValue <= oldValue + maxSubTree[children]){
                goodNeighbours[node].insert(children);
                maxSubTree[node] = oldValue + maxSubTree[children];
            }
        }
    }
}


void findMaxSubgraph(int node, int parent, vector<vector<int>> &adj, vector<int> &maxSubgraph, vector<int> &color, vector<set<int>> &goodNeighbours){
    
   if( parent != 0){

        int extraCost = maxVal[parent] - max(0,maxSubgraph[node]);
        extraCost = max(0, extraCost);
        maxVal[node] += extraCost;
   }
   else {
        maxVal[node] = maxSubgraph[node];
   }

   for(int x : adj[node]){
    if( x != parent){
        findMaxSubgraph(x, node, adj, maxSubgraph, color, goodNeighbours);
    }
   }
}


int main()
{

    int n;
    cin >> n;
    vector<int> color(n+1, 0);
    for(int i = 1; i <= n ; i ++){
        cin >> color[i];
        if(color[i] == 0) color[i] = -1; 
    }

    vector<vector<int>> adj(n+1);

    vector<set<int>> goodNeighbours(n+1);


    for( int i = 0 ; i < n -1 ; i ++){
        int u, v;
        cin >> u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    vector<int> maxSubTree(n+1, -1e9);

    dfs(1,0, adj, maxSubTree, color, goodNeighbours);

    vector<int> maxSubgaph = maxSubTree;

    maxVal = maxSubgaph;

    findMaxSubgraph(1,0, adj, maxSubgaph, color, goodNeighbours);

    for(int i = 1 ; i <= n ; i ++){
        cout << maxVal[i] << " "; 
    }

    return 0;
}