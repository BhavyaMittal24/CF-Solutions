#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n+1);

    map<int, vector<int>> mp;
    // idx -> vector<int> indices
    for(int i = 1 ; i <= n; i ++ ) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    if(mp.size() == 1){
        cout << "NO\n";
        return; 
    }

    auto it = mp.begin();

    int cnt = 0;
    int firstNode = -1;
    int firstGang = -1;
    int lastNode = -1;
    // for(auto it : mp){
    // stores the pair
    // Key : it.first , value : it.second
    //}

    vector<pair<int,int>> edges;

    while( it != mp.end()){

        vector<int> sameGangNodes = it->second;

        if(cnt == 0){
            firstNode = sameGangNodes[0];
            firstGang = it->first;
        }

        else {
            for(auto node : sameGangNodes){
                edges.push_back({firstNode,node});
                lastNode = node;
            }
        }
        cnt++;
        it++;
    }

    for(auto node : mp[firstGang]){
        if(node == firstNode) continue;
        edges.push_back({lastNode, node});
    }

    cout << "YES\n";
    //cout << firstGang << " " << firstNode << "\n";
    for(auto edge : edges){
        cout << edge.first << " " << edge.second << "\n";
    }
    return;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}