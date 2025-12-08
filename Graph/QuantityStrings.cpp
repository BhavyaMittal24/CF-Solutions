#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

class DSUByRank{
    public:
    vector<int> parent, rank;

    DSUByRank( int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
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


long long binaryExp( long long base, long long exp){
    long long ans = 1;
    base = base % mod;

    while(exp > 0){
        // last bit for the exp
        // is the LSB set or not : 2 : 10 
        // 10 & 1
        if(exp & 1){
            ans = (ans * base) % mod; 
        }
        base = (base * base) % mod;
        exp = exp >> 1; // divide by 2
    }
    return ans;
}

long long binaryLifting(long long base ,long long exp){

    long long ans = 1;
    base = base % mod;

    int m = log2(exp);
    // m finds the MSB for the exponent

    for(int i = 0; i <= m ; i ++){
        // ith bit is set :
        // : 2 and 0th bit
        // 10 & 01
        if( (1 << i) & exp){
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
    }
    return ans;
}

int main(){
    int n, k, m;
    cin >> n >> m >> k;

    DSUByRank DSU(n);
    for(int i = 0 ; i <= n-k ; i ++){
        int left = i;
        int right = i + k -1;
        while( left <= right){
            DSU.unionByRank(left, right);
            left ++;
            right --;
        }
    }

    long long cc = 0;
    for(int i = 0 ; i < n ; i ++){
        if(DSU.findSet(i) == i) cc ++;
    }

    long long ans = 1;
    ans = binaryLifting(m, cc);

    cout << ans << endl;
    return 0;
}