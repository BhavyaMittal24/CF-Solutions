#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    int op = 0;

    vector<int> arr(n);
    for(int i = 0; i< n; i ++){
        cin >> arr[i];
    }

    int i = 0;
    while(i < n){

        if(arr[i] == 0){
            op++;
            i++;
            continue;
        }

        else if(arr[i] == 1){

            if( (i+1 < n)  && (i+2 < n) ){
                
                if( (arr[i+1] == 1) && (arr[i+2] == 1) ){
                    op++;
                    i = i+3;
                    continue;
                }

                else if(arr[i+1] == 2){
                    op++;
                    i = i+2;
                    continue;
                }
                else {
                    i++;
                    continue;
                }
            }

            else if( i + 1 < n){
                if(arr[i] == 2){
                    op++;
                    i = i+2;
                    continue;
                }
                else {
                    i++;
                    continue;
                }
            }

            else {
                i++;
                continue;
            }
        }
        else {
            // arri = 2

             if( (i+1 < n)  && (i+2 < n) ){
                
                if( (arr[i+1] == 2) && (arr[i+2] == 2) ){
                    op++;
                    i = i+3;
                    continue;
                }

                else if(arr[i+1] == 1){
                    op++;
                    i = i+2;
                    continue;
                }
                else {
                    i++;
                    continue;
                }
            }

            else if( i + 1 < n){
                if(arr[i] == 1){
                    op++;
                    i = i+2;
                    continue;
                }
                
                else {
                    i++;
                    continue;
                }
            }

            else {
                i++;
                continue;
            }
        }
    }

    cout << op << "\n";
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;

    while(t--){
        solve();
    }
    return 0;
}