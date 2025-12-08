#include<bits/stdc++.h>
using namespace std;

const long long INF = LONG_LONG_MAX;

int main(){

    int n, m;
    cin >> n >> m;

    // wi <= 1e6
    // n,m <= 1e5
    vector<vector<pair<int,int>>> adj(n+1);

    // u -> [{v,w} ..] 
    for(int i = 0; i < m;  i ++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // storing the minimum distance from the source
    // inintially the min distance is inifinity
    vector<long long> distance(n+1, INF);


    // by default its a max heap : we want a min heap
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    set<pair<long long,int>> st;
    
    // distance[1] = 0;
    // <distance, node> from thr source node
    st.insert({{0,1}});

    distance[1] = 0;
    vector<int> parent(n+1,0);
    
    parent[1] = 0;

    while( !st.empty()){
        // once a node is processed, it's dostance array is not updated anymore
        // the nodes which are popped from the queue have the minimum possible disance and are updatee correctly

        pair<long long,int> top = *st.begin();
        // log(Heapsize) : each node is popped only once
        st.erase(st.begin());
        
        long long currDist = top.first;
        int node = top.second;

        // if distance array for this node has a lesser distance or equal, we dont need it to relax the distances for other nodes 
        if( currDist > distance[node]) {
            continue;
        }

        // see all the adjancent elements and their weights 
        for(auto neighbour : adj[node]){
            int v = neighbour.first;
            int w = neighbour.second;

            // the already set distance is more than by takign the currentNode
            if( distance[v] > currDist + 1ll*w ){
                
                //distance[v] = currDist + w;

                if(st.find({distance[v], node}) != st.end()){
                    st.erase({distance[v], node});
                }
                distance[v] = currDist + 1ll*w;
                parent[v] = node;

                // each node can be pushed deg node times : deg node if there is a better distance found
                st.insert({distance[v], v});
            }
            
        }
    }

    // n nodes in the queue, 2m nodes at max in the heap which are inserted
    // tc: o(n*logm + m* logm)
    if(distance[n] == INF){
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;

    int curr = n;

    while(curr != 0){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    
    for(int i : path){
        cout << i << " ";
    }

    return 0;
}