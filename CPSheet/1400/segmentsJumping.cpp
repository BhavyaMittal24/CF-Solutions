#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, map<string,int> & order, vector<long long> & dp){

    if( node == 1){
        dp[node] = 1;
    }

    int cntEdgesComingBefore = 0;

    // pci , check if all pci come after p1 p

    long long maxChildren = 0;
    for(int x : adj[node]){

        if(x == parent) continue;

        dfs(x, node, adj, order, dp);
        
        string nodeParent = "";
        string nodeChild = "";

        if( node < parent){
            nodeParent += to_string(node) + "#" + to_string(parent);
        }
        else {
            nodeParent += to_string(parent) + "#" + to_string(node);
        }

        if(x < node){
            nodeChild += to_string(x) + "#" + to_string(node); 
        }
        else {
            nodeChild += to_string(node ) + "#" + to_string(x);
        }

        int childRank = order[nodeChild];
        int nodeRank =  order[nodeParent];

        if( childRank < nodeRank ) maxChildren = max(maxChildren, 1 + dp[x]);

        else maxChildren = max(maxChildren, dp[x]);
    }

    // if even one of the children comes before the parent node 
    // if no child comes before the parent gets in the rank orering

    //cout << node << " " << cntEdgesComingBefore << " "  << sumChildren << "\n";
   
    dp[node] = dp[node] + maxChildren;

    // forna laaf node , the ans is 0
}

bool isPossible(int k, vector<pair<int,int>> &ranges){

    bool check = true;

    int start = 0;
    int end = 0;
    for(int i = 0; i < ranges.size(); i ++){

        int si = ranges[i].first;
        int ei = ranges[i].second;

        start = start -k;
        end = end + k;
        // start, end   : si,ei check if they intersect or not
        if(max(si, start) <= min(ei, end)){
            start = max(si,start);
            end = min(ei, end);
        }
        else {
            check = false;
            break;
        }
    }
    return check;
}
void solve(){

    int n;
    cin >> n;

    // n queries li,ri
    
    vector<pair<int,int>> ranges(n);
    for(int i = 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        ranges[i] = {l,r};
        // dsegment range is l to r
    }

    // f(k) = T if we can cross all n ranges from 1 to n

    int low = 0;
    int high = 1e9;
    
    int ans = -1;
    while( low <= high){

        int mid = (low + high)/2;
        // check if possible to visit all segments with this value of k

        if(isPossible(mid, ranges)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
            // l   h mid      h
        }
    }
    cout << ans << "\n";
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}