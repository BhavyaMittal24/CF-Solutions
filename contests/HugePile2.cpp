#include<bits/stdc++.h>
using namespace std;

// find the min depth of a node which has a value k from the root node having value n
int findDepth(int node, int k, map<int,int> & dp){

    if(node == k){
        return 0;
    }

    if(node <= 1) {
        return 1e9;
    }

    if( dp.count(node) != 0) return dp[node];

    int leftNode = node/2;
    int rightNode = node/2 + (node % 2);

    int leftDepth = findDepth(leftNode, k, dp);
    int rightDepth = findDepth(rightNode, k, dp);

    int ans = min(leftDepth, rightDepth);
    if( ans != 1e9) ans = ans + 1;
    return dp[node] = ans; 
}

void solve(){

    int n , k;
    cin >> n >> k;

    // mp storing the min depth for a given node k if it exists in a tree with 2 distinct nodes at each level
    
    map<int,int> dp;

    int ans = findDepth(n, k, dp);
    if(ans == 1e9) ans = -1;
    cout << ans << "\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}