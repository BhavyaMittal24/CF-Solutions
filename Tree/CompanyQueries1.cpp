#include<bits/stdc++.h>
using namespace std;


int kthParent(int x, int k, vector<int> &parent){

    int curr = x;
    while(curr !=0 && k--){
        curr = parent[curr];
        // jumps ny 1 step up
    }
    return curr;
}
int main(){

    int n, q;
    cin >> n >> q;

    vector<int> parent(n+1,0);
    parent[1] = 0;

    for(int i=2;i<=n;i++){
        cin >> parent[i];
    }

    vector<pair<int,int>> queries(q);

    for(int i=0;i<q;i++){
        int x, k;
        cin >> x >> k;
        queries[i] = {x,k};
    }

    for(int i=0;i<q;i++){
        int x = queries[i].first;
        int k = queries[i].second;
        int ans = kthParent(x,k,parent);

        if( ans == 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}