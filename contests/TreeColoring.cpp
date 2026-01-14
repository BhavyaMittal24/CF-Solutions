#include <bits/stdc++.h>
using namespace std;

int maxNodeLevel;
void dfs(int node, int parent, vector<vector<int>> &adj, int level, vector<int>& levelCount)
{
    levelCount[level]++;
    maxNodeLevel = max(maxNodeLevel, levelCount[level]);

    for (int x : adj[node])
    {
        if (x != parent)
        {
            dfs(x, node, adj, level + 1, levelCount);
        }
    }
}

void solve()
{

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    // 1 based indexing for the tree
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // store nodes for each level
    vector<int> levelCount(n + 1, 0);

    maxNodeLevel = 0;

    dfs(1, 0, adj, 0, levelCount);

    for (int i = 1; i <= n; i++)
    {

        int children = adj[i].size();
        if (i != 1)
            children--;

        if (children == maxNodeLevel)
            maxNodeLevel++;
    }

    cout << maxNodeLevel << "\n";

    vector<int> color(n+1, 0);
    // colors from 1 to maxNodeLevel

    // queue contains {node, parent}
    set<int> presentColors;

    set<int> allowedColors;
    for(int i = 1; i <= maxNodeLevel ;i ++){
        allowedColors.insert(i);
        presentColors.insert(i);
    }

    queue<pair<int,int>> q;

    q.push({1,0});

    // color[1] = 1;

    vector<int> parentLevel;


    int lastNode = 0;
    while(!q.empty()){
       
        int qSize= q.size();

        
        // nodes at one level : each node does not contain the same color as it's parent and also the color that has been alredy occupied
        for(int i = 0; i < q.size(); i ++){

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            if( i == 0 && lastNode != 0 && lastNode != parent)
            {
                color[node] = color[lastNode];
                presentColors.erase(color[node]);

                for(int x : adj[node]){
                    if( x != parent ){
                        q.push({x, node});
                    }
                }  

                if( adj[node].size() >= 2 )lastNode = node;

                continue; 
            }

            int nodeParentColor = color[parent];
            int nodeColor = 0;

            if( *presentColors.begin() == nodeParentColor){
                presentColors.erase(presentColors.begin());
                nodeColor = *presentColors.begin();
                presentColors.insert(nodeParentColor);
            }

            else {
                nodeColor = *presentColors.begin();
            }
            
            presentColors.erase(nodeColor);

            color[node] = nodeColor;
            for(int x : adj[node]){
                if( x != parent ){
                    q.push({x, node});
                }
            }

            if( adj[node].size() >= 2 )lastNode = node;
        }

        presentColors = allowedColors;
    }

    // assigmed colors to each node
    vector<vector<int>> nodesPerColor(maxNodeLevel + 1);

    for(int i = 1; i <= n; i ++){
        // color -> nodeNumber
        nodesPerColor[color[i]].push_back(i);
    }

    for(int i = 1; i <= maxNodeLevel ; i++){
        cout << nodesPerColor[i].size() << " ";
        for(int j : nodesPerColor[i]) cout << j << " ";
        cout << "\n";
    }
    return;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}