#include<bits/stdc++.h>
using namespace std;

// basic DSU implementation taking 0(n) time at max for a tree of n nodes : n connected components
class DSUNaive{
    vector<int> parent;

    DSUNaive( int n){
        parent.resize(n+1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findSet(int x){
        if( x == parent[x]) return x;
        return findSet(parent[x]);
    }

    void unionSet(int u, int v){
        // get the roots for both u and v
        u = findSet(u);
        v = findSet(v);

        // connect the root of v to the root of u
        if( u != v){
            parent[u] = parent[v]; 
        }
    }
};

class DSUBySize {
    vector<int> parent, size;

    DSUBySize( int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1; i <= n; i++){
            parent[i] = i;
        }
    }

    // by merging using Sizes : small to large merging : we are capping the height of the tree by 0(log2n)
    // I can only merge log2(n) times
    int findSet(int x){
        if( x == parent[x]){
            return x;
        }
        return findSet(parent[x]);
    }

    void unionSet(int u, int v){
        u = findSet(u);
        v = findSet(v);

        if( u != v){
            // merge always u to v
            // u -> v
            // merge smaller into larger
            if(size[u] > size[v]){
                swap(u,v);
            }
            parent[u] = v;
            size[v] += size[u];
        }
    }
};


class DSUByRank{
    vector<int> parent, rank;

    DSUByRank( int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    // path compression : it memoises the answer for findSet(x) : 
    // x -> a -> b -> c -> root
    // findSet(x) will memoise the parent[x] for all the nodes along the path and make their parent as root

    // Path compression makes complexity for searching 0(logn) over an average
    // and if you are union by rank, the complexity even goes down to 0(alpha(n)) ~ 0(4)
    
    int findSet(int x){
        if( x == parent[x]) return x;
        return parent[x] = findSet(parent[x]);
    }

    void unionByRank( int u, int v){
        u = findSet(u);
        v = findSet(v);

        if( u != v){
            if(rank[u] > rank[v]){
                parent[v] = u;
            }
            else if( rank[u] < rank[v]){
                parent[u] = v;
            }
            else {
                parent[u] = v;
                rank[v] ++;
            }
        }
    }
};
