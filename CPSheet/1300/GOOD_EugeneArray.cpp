#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n+1,0);
    vector<long long> prefixSum(n+1, 0);

    for(int i = 1; i <= n ; i++){
        cin >> arr[i];
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    set<long long> st;
    st.insert(0);

    int j = 0;
    int i = 1;

    int lastJ= -1;
    long long cnt = 0;
  
    // i ........j  n
    while( i <= n){

        // i j .. matchj
        
        if( i >= j && j <= n){

            // find the next j which matches
            j++;
            while(  (j <= n) &&  ( st.count(prefixSum[j]) == 0) ){
                st.insert(prefixSum[j]);
                j++;
            }  
            // found a match where j : pref
            lastJ = j-1;

            cout << i << " " << j << " " << lastJ << "\n";
        }

        if(i <= lastJ){
            cout << i << " " << lastJ << "\n";
            cnt += (lastJ - i+1);
        }
        i++;
    }

    cout << cnt << '\n';
    return 0;
}