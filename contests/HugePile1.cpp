#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;

    int steps = 0;
    queue<long long> q;
    map<long long,int> vis;

    q.push(n);
    vis[n] = 1;

    int ans = -1;

    bool isFound = false;
    while( !q.empty() && !isFound){
        
        int qSize = q.size();
        
        while( (qSize--) && !isFound){
            int node = q.front();
            q.pop();

            if( node == k) {
                ans = steps;
                isFound = true;
                break;
            }

            long long leftNode = node/2;
            long long rightNode = node/2 + (node % 2);

            if(node <= 1) continue;

            if( !vis[leftNode]) {
                q.push(leftNode);
                vis[leftNode] = 1;
            }

            if( !vis[rightNode]){
                q.push(rightNode);
                vis[rightNode] = 1;
            }
        }
        steps ++;
    }

    cout << ans  << "\n";
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