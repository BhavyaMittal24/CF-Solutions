#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    string a;
    string b;
    cin >> a;
    cin >> b;

    // tell if the strings can be made same by fliping bits of even length prefixes
    if( a== b){
        cout << "YES \n";
        return;
    }


    int windowLen = 0;

    bool isPossible = true;
  
    int cnt0s = 0;
    int cnt1s = 0;

    int winCnt0 = 0;
    int winCnt1 = 0;

    for(int i = 0; i < n; i ++){
        if(a[i] == '0') cnt0s++;
        else cnt1s++;
    }

    int cntFlips  = 0;

    //cout << cnt0s << " " << cnt1s << "\n";

    for(int j = n -1; j >= 0; j --){

        // odd no of flips
        char aj = a[j];

        if(cntFlips % 2 == 1){
            if(a[j] == '0') aj = '1';
            else aj = '0';
        }

        if(aj == b[j]){
            // length of flip values
            
            //cout << windowLen << " " << cnt0s <<  "  "<< cnt1s << "\n"; 
            if(windowLen > 0 && (cnt0s == cnt1s)){
                // oossible to flip the bits
                cntFlips++;
                // we go back because the same bit now becomes different
               
                cnt0s -= winCnt0;
                cnt1s -= winCnt1;
                swap(cnt0s, cnt1s);
                winCnt0 = 0;
                winCnt1 = 0;
                windowLen= 0;
                j++;
            }

            else if(windowLen > 0 && (cnt0s != cnt1s)) {
                isPossible = false;
                break;
            }

            else if(windowLen == 0){
                if(aj == '0') {
                    cnt0s--;
                }
                else {
                    cnt1s--;
                }
            }
        }

        else {
            windowLen++;
            if(a[j] == '0') winCnt0 ++;
            else winCnt1++;
         }
    }

    if(windowLen != 0 && cnt0s != cnt1s) isPossible = false;

    if(isPossible) {
        cout << "YES\n";
    }

    else {
        cout << "NO\n";

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