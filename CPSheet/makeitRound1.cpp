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

long long exp(long long base, long long exp){

    long long ans = 1;
    
    while(exp > 0){

        if( exp & 1){
            ans = ans * base;
        }
        base = base * base;
        exp = exp >> 1;
    }
    return ans;
}

void solve(){

    int n, m;
    cin >> n >> m;

    // find the largest powers of 2 and 5 in m
    int x = log2(m);
    int y = 0;

    int temp  = m;
    while(  (temp / 5 ) > 0){
        y++;
        temp = temp/5;
    }
    // we found the max powers of 2 and 5

    long long ans = 0;

    int cntTen = 0;

    int cnt2 = log2(n);
    int cnt5 = 0;
    temp = n;

    while( (temp/5) > 0){
        cnt5++;
        temp = temp/5;
    }

    for(int i = 0; i <= x; i ++){
        for(int j = 0; j <= y; j ++){

            long long k = 1ll*exp(2,i) * exp(5,j);
            if( k > m) continue;

            long long rem = m/k;

            long long tempAns = k * rem * n;

            int cnt10 = 0;
            long long temp = tempAns;

            while( temp % 10 == 0){
                cnt10++;
                temp = temp/10;
            }

            if(cntTen < cnt10) {
                ans = tempAns;
                cntTen = cnt10;
            }
            else if( cnt10 == cntTen) {
                ans = max(ans, tempAns);
            }
        }
    }

    if(cntTen == 0){
        ans = max(ans, 1ll* n * m);
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