#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    // m unqiue presents
    // ki ; for each friend : max present number till which he can buy or if no present then just give cki collars

    vector<int> presentNumber(n+1,0);
    vector<int> cost(m+1,0);

    for(int i = 1; i <= n; i++){
        cin >> presentNumber[i];
    }

    for(int i = 1; i <= m; i++) cin >> cost[i];

    sort(presentNumber.begin(), presentNumber.end());

    int i = 1; // pointer for the present
    int j = n; // pointer for the friend
    
    long long minCost = 0;

    // 1 1 3 3 6 7 8
    // 9 unique oresenrs

    while( j >= 1){

        if(presentNumber[j] >= i){
            minCost += 1ll*cost[i];
            i++;
        }
        else {

            minCost += 1ll*cost[presentNumber[j]];
        }
        j--;
    }

    cout << minCost << "\n";
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