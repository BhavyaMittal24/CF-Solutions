#include<bits/stdc++.h>
using namespace std;

int compare(vector<int> &a, vector<int> &b){

    // keeps a fixed and moves b
    int cnt = 0;

    int n = a.size();

    for(int j = 0 ; j < n; j ++){

        bool isValid = true;
        for(int i = 0; i < n; i ++){
            if( a[i] >= b[ (i+j ) % n]) {
                isValid = false;
            }
        }
        if(isValid) {
            cnt++;
        }
    }
    return cnt;
}


void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n ; i ++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i ++){
        cin >> c[i];
    }

  
    int x = compare(a,b);
    int y = compare(b,c);
    // int z = compare(b,c);

    cout << 1ll * x * y * n << endl;

}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}