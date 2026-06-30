class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);

    // u -> [{v,w} ..] 
    for(int i = 0; i < edges.size();  i ++){
        int u =edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // storing the minimum distance from the source
    // inintially the min distance is inifinity
    // the distanc array serves as a visisted array which helps us in tracking if some node is reacahbale or not
    
    // it is the single source of trith for hoe far each node is at all times
    vector<int> distance(n+1, 1e9);


    // by default its a max heap : we want a min heap
    //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    queue<pair<int,int>> pq;
    distance[src] = 0;
    // <distance, node> from thr source node
    pq.push({0,src});

    vector<int> parent(n+1,0);
    
    parent[1] = 0;

    while( !pq.empty()){
        // once a node is processed, it's dostance array is not updated anymore
        // the nodes which are popped from the queue have the minimum possible disance and are updatee correctly

        pair<int,int> top = pq.front();
        // log(Heapsize) : each node is popped only once
        pq.pop();
        
        int currDist = top.first;
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
            if( distance[v] > currDist + w ){
                // distance for v is updated instantly : 
                // we can store the parent from the node -> v
                // if the pq contanis some other node in its top which when tried for relaxation, it won;t be able to relax the node v unless it has even smaller disttance
                distance[v] = currDist + w;
            
                parent[v] = node;
                // each node can be pushed deg node times : deg node if there is a better distance found
                pq.push({distance[v], v});
            }
            
        }
    }
    return distance;
    }
};