#include <bits/stdc++.h>
using namespace std;

// given two nodes, A and B, tell me if I A is connected to B
// find the shortest possible distance between two nodes and if they are connected or not in a SOcial netwrok which is very possible
// one frined -> multiple friends

// Start from A -> check if B can be found or not.
// In a plain BFS, A-> 6nodes -> 6 more ... and so on

// branching factor is b
// for a given depth d : total nodes searched at the dth level : b^d
// total sc : o(b^d)

// We use a bidirectional BFS for such scale : Start from both A and B and see if we can meet in the middle
// Without loss of generality : meet in the middle -> d/2
// total nodes visited : Sc ->   O( b^ (d/2)) for each node : 2 * (b^ (d/2))\


// branching factor = b
// total depth = 6 : each person can have upto 6 layers based on the theory : depth = 6 at max : 6th friend of friend
// given space is a constraint where you only know upto 6 levels of branching for each person and each person can have arounf 100 friends
// 100^6 hence are the totla nodes

// given a graph, find if a and b are connected and what level of friend they are :
// 0, (a and b are same)
// 1: a and b are direct friends
// 2 a and b have a common friend

int distance(int src, int dest, int n, vector<vector<int>> &adj)
{

    queue<int> q1;
    queue<int> q2;

    vector<int> dist1(n+1,1e9); // dist from node1 : src
    vector<int> dist2(n+1, 1e9); // dist from node2 : dest

    int ans = 1e9;

    int meet = 0;

    if( src == dest) return 0;

    q1.push(src);
    q2.push(dest);

    dist1[src] =0;
    dist2[dest] = 0;

    // if q1 is empty and no common middle point has not been reached, we can just assume no common point is there for us
    while( (!q1.empty() && !q2.empty() ) && !meet){

        // expand only a single queue at one time
        queue<int>& q = (q1.size() && q1.size() <= q2.size()) ? q1 : q2;

        vector<int> &dis = (q1.size() && q1.size() <= q2.size()) ? dist1 : dist2;
        vector<int> &disOther = (q1.size() && q1.size() <= q2.size()) ? dist2 : dist1;

        int qSize = q.size();

        while(qSize-- && !meet){
            int node = q.front();
            q.pop();

            for(int x : adj[node]){
                // x has been visited by other node
                if( disOther[x] != 1e9 ){
                    ans = dis[node] + 1 + disOther[x];
                    meet = 1;
                    // return ans;
                    break;
                }

                if(dis[x] == 1e9){
                    q.push(x);
                    dis[x] = dis[node] + 1;
                }
            }
        }
    }

    if(!meet) return -1;
    return ans;
   
}

int main()
{

    int n, m;
    cin >> n >> m;

    int src;
    int dest;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u -> v
        //  v -> u
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> src >> dest;

    cout << distance(src, dest, n, adj) << "\n";
    return 0;
}
