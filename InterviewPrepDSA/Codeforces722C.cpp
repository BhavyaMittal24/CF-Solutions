#include<bits/stdc++.h>
using namespace std;


class DSU {

    int n;
    vector<int> rank;
    vector<int> parent;
    vector<long long> sum;
    vector<long long> arr;
    public :
    long long maxi;
    DSU(int n, vector<long long> a){
        maxi = 0;
        arr = a;
        rank.assign(n+1, 0);
        parent.assign(n+1, 0);
        sum.assign(n+1, 0);
        for( int i = 1; i <= n; i ++){
            sum[i] = arr[i]; // value for the ith node
        }
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findSet(int x){
        if(x == parent[x] ) return x;

        return parent[x] = findSet(parent[x]);
    }

    void unionSet(int u, int v)
    {
        u = findSet(u);
        v = findSet(v);
        if( u == v){
            return;
        }

        if(rank[u] < rank[v]){
            swap(u,v);
        }
        parent[v] = u;
        sum[u] += sum[v];
        maxi = max(maxi, sum[u]);
        if(rank[u] == rank[v]){
            rank[u]++;
        }
    }

};

int main(){

    int n;
    cin >> n;

    // arri  4 1 2 3 5
    // per   2 3 4 1 5 : order of indexes which should be deleted
    // deleteing per[i]
    // 4  2 3 5
    // 4    3 5
    // 4      5
    //        5
    //        
    // return after each deletion, the maximum sum for a given segment/ subarray
    // DSU stores sum for each connected component
    // and a variable max to trakc max sum for each connected component

    vector<long long> arr(n+1, 0);
    vector<int> perm(n+1,0);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i]; // 4 1 2 3 5
    }

    for(int i = 1; i <= n; i ++){
        cin >> perm[i]; // the indexes I need to add in reverse order
    }

    DSU dsu(n, arr);
    // adding perm[i];

    vector<int> vis(n+1, 0); // keep track if indices hve been taken or not

    vector<long long> maxSum;
    maxSum.push_back(0);

    for(int i = n; i >= 2; i --){
        // connect 0 and any new node if in case not picked up
        int idxToAdd = perm[i]; // adding index 4 to the array
        // checking if 3 and 5 exists or not, else connect them to 0
        vis[idxToAdd] = 1;
        // include the value for idxToAdd : vis[idx] means if the index i is included or niot. and when cinnecting, check if existing also there or nit
        // if no neighbour are there then let it be, dont connect it, it can be stored as the mx element in the array
        // will onyl connect it to a not 0 idx.  1 2 3 4 5
        int n1 = (idxToAdd == n ) ? 0 : (vis[idxToAdd+1] == 0) ? 0 : idxToAdd+1;  
        int n2 = (idxToAdd == 0) ? 0 : (vis[idxToAdd -1] == 0) ? 0 : idxToAdd - 1;
        if(n1 != 0) dsu.unionSet(idxToAdd, n1);
        if(n2 != 0) dsu.unionSet(idxToAdd, n2);

        dsu.maxi = max(dsu.maxi, arr[idxToAdd]);
        maxSum.push_back(dsu.maxi);
    }
    reverse(maxSum.begin(), maxSum.end());
    for(auto x : maxSum){
        cout << x << ' ';
    }

    return 0;
}