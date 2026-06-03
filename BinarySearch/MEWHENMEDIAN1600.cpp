#include<bits/stdc++.h>
using namespace std;

//  if we can get a min value x after performing a set of operation to reduce the answer
bool isPossible(int x, vector<int> &a, vector<int> &b){

    // mid value is possible
    int n = a.size(); 
    vector<int> ans(n);

    for(int i = 0; i < n; i ++){

        if((a[i] >= x) && (b[i] >= x)){
            ans[i] = 1;
        }
        else if((a[i] < x) && (b[i] < x)){
            ans[i] = -1;
        }
        else {
            ans[i] = 0;
        }
    }

    int val = 0;
    for(int i = 0; i < n; i ++){
        if( ans[i] == 0) continue;

        // -, -, +, + ..., -, + , -
        if(ans[i] == -1){
            while( (ans[i] != 1) && (i < n)){
                i++;
            }
            val += -1;
            i--;
        }

        else {
            val++;
        }
    }

    if( val > 0) return true;
    return false;
}

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];

    // find the max of min(a1,b1) after a seqwence odf operations : 
    // various min values : 
    // check id possible to have a value x :
    // if possible to have a min value >= x :
    // f(x) = is possible to have min value >= x
    // T T T T T T... 50. F F F F
     

    //   1<= a1 <= 2n 
    int low = 1;
    int high = 2*n;

    int ans = -1;

    while( low <= high){
        int mid = (high + low)/2;

        // check if possible to get a value >= mid after perdorming some operarions
        if(isPossible(mid, a, b)){
            ans = mid;
            // x is possible : pissible ot have the min value >= x after some operatrions : try up
            low = mid +1;
        }
        else {
            high = mid-1;
        }
    }

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