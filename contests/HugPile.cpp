#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int k;
    cin >> n >> k;

    int node = n;

    bool isFound = false;
    int steps = 0;


    if( node == k ){
        isFound = true;
    }

    while(node != 1 && !isFound){
       

        int left = 0;
        int right = 0;

        if( node % 2 == 0){
            left = node/2;
            right = node/2;
        }

        else {
            left = node/2;
            right = node/2 + 1;
        }
        
        steps++;

        if( left == k || right == k){
            isFound = true;
            break;
        }

        node = left;
    }

    if(!isFound) {
        cout << "-1 \n";
    }
    else {
        cout << steps << "\n";
    }
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