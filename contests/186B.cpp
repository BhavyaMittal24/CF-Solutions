#include<bits/stdc++.h>
using namespace std;


void solve(){
    int w, b;

    cin >> w >> b;

    int maxLayers1 = 0;

    int chocolateRequired = 1;

    vector<int> leftAmount = {w,b};
    int currentTurn = 0;

    while( leftAmount[currentTurn] >= chocolateRequired){

        maxLayers1++;
        leftAmount[currentTurn] -= chocolateRequired;
        currentTurn = currentTurn ^ 1;
        chocolateRequired *= 2;
    }

    int maxLayers2  = 0;
    currentTurn = 0;
    leftAmount = {b,w};
    chocolateRequired = 1;

    while( leftAmount[currentTurn] >= chocolateRequired){

        leftAmount[currentTurn] -= chocolateRequired;
        currentTurn = currentTurn ^ 1;
        chocolateRequired *= 2;
        maxLayers2++;
    }

    cout << max(maxLayers1, maxLayers2) << endl;
}

// log(n) -> log(n ^ 2/3)
int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}