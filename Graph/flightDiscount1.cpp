#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> adj(n+1);

    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w}); // u -> v : directed edge : 
    }


    // pq : {dist, {node, usedOrNot}}
    // expand along the min imim distance whether coupon is used ot not
    priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> pq;

    vector<vector<long long>> distance(n+1, vector<long long> (2, 1e18));
    // distance[node][used] : min distance required toreachfrom src to node such that coupon is used or not

    distance[1][0] = 0;

    distance[1][1] = 0;
    pq.push({0, {1,0}});
    pq.push({0, {1,1}});

    while( !pq.empty()){

        long long nodeDist = pq.top().first;
        int node = pq.top().second.first;
        int used = pq.top().second.second;

        //cout << nodeDist << " " << node << " " << used << endl;
        pq.pop();

        // stale entries which have greater distance to the nde when the coupin used state is same
        if( nodeDist > distance[node][used]) continue;

        for(auto x : adj[node]){

    
            int v = x.first;
            long long wt = x.second;

            //cout << v << " " << wt << " " << node << endl;
            if( used == 1){

                if(distance[v][1] > nodeDist + wt){
                    distance[v][1] = nodeDist + wt;
                    pq.push({distance[v][1],{v, 1}});
                }
            }
            else {

                // try using the coupon and not using it
                if(distance[v][1] > nodeDist + wt/2 ){
                    distance[v][1] = nodeDist + wt/2;
                    pq.push({distance[v][1],{ v, 1}});
                }

                if( distance[v][0] > nodeDist + wt){
                    distance[v][0] = nodeDist + wt;
                    pq.push({distance[v][0],{v, 0}});
                }
            }
        }
    }

    cout << min(distance[n][0], distance[n][1]) << endl;
    return 0;
}