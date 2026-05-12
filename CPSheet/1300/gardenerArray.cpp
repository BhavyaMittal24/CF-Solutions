#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> st;

    bool isPossible = false;
    for(int i = 0; i < n; i ++){
        int k;
        cin >> k;

        if( i == 0){
            for(int j = 0; j < k; j ++){
                int x;
                cin >> x;
                st.insert(x);
            }
        }

        // 1 2 3 4
        // 3 4
        else {
            int cnt = 0;
            // vector<int> currBits;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                //currBits.push_back(x);
                if(st.find(x) != st.end()){
                    // present in st
                    cnt++;
                }
                else {
                    st.insert(x);
                }
            }

            // all the elements are present for ith ci is a part of the set already from 1 to i-1
            if(cnt == k) {
                isPossible = true;
            }

            // npw if cnt is not k then what : ? ie new layer of bits are not all included in the previou sets
            // in this case: if the new super set has all the elements of the currebt layer : then alsi it is true
            // bsically ; 1, 1,2,3,4 : 1,2,3,4 : same as the new layer : [1,2] , [2]

            // new size : old size + currLayer
            if( k == st.size()){
                isPossible = true;
            }
        }
    }

    if(isPossible) {
        cout << "yes\n"; 
    }
    else {
        cout << "no\n";
    }
    return;
}


int main(){
    
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}