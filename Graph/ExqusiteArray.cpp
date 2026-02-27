#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> sz;

// memoisation reduces the tc by 0(n)
int findSet(int x){
    if( x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);

    if( u != v) {
        if(sz[u] < sz[v]){
            swap(u,v);
        }

        parent[v] = u;
        sz[u] =  sz[u] + sz[v];
    }
}

long long cntSubArrays(int x){
    x = findSet(x);
    return  1ll* sz[x] * (sz[x] - 1) / 2;
}

void solve(){
    
    int n;

    cin >> n;

    vector<int> arr(n+1,0);
    
    map<int,vector<int>> diff;

    vector<long long > ans;

    for( int i = 1; i <= n ; i++) {
        cin >> arr[i];
        if( i >= 2){
            diff[abs(arr[i] - arr[i-1])].push_back(i-1); // therefore e
            // a[i] - a[i-1] -> stored as i-1 : 
            // from i-1 -> two indices i-1,i
        }
    }

    parent.assign(n+1,0);
    sz.assign(n+1,1);

    for(int i = 1 ; i <=n ; i++) parent[i] = i;


    // k -> i ( i, i -1) this means these two indices have that difference btween them forming a subarray fo size 2
    long long cnt = 0;

    for(int k = n-1 ; k >= 1 ; k--){

        for(int nodePairs : diff[k]){

            cnt -= cntSubArrays(nodePairs);
            cnt -= cntSubArrays(nodePairs+1);

            unionSet(nodePairs, nodePairs+1);
            cnt += cntSubArrays(nodePairs);
        }
        ans.push_back(cnt);
    }

    reverse(ans.begin(), ans.end());

    for(auto node : ans){
        cout << node << ' ';
    }
    cout << "\n";
    return;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}