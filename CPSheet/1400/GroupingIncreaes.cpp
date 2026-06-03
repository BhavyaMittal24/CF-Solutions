#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    //  1 <= ai <= n , n <= 2 * 1e5

    // s : [          ]
    // t : [          ]

    // only the last value of s and t matters : because we are concerned with ai > ai+1 or bi > bi+1
    // penalty will increase only whem ai < ai+1 1, 5 .... 4,6

    // last value is what we are concerned with : use this in DP

    int x = INT_MAX;
    int y = INT_MAX;

    int p = 0;

    for(int i = 0; i < n; i ++){
        
        if(arr[i] <= x && arr[i] <= y){

            // smaller from both :  no inc in penalty but add to the smaller element
            if( x < y){
                x = arr[i];
            }
            else {
                y = arr[i];
            }
        }

        else if(arr[i] > x && arr[i] > y){

            // place at smaller once because larger one can take more values for penalty
            if(x < y){
                x = arr[i];
            }
            else {
                y = arr[i];
            }
            p ++;
        }

        else {

            if( x > y){

                if( arr[i] <= x){
                    x = arr[i];
                }
            }
            //  ..........     x  arri  y
            else {

                if(arr[i] <= y){
                    y = arr[i];
                }
            }
        }
    }

    cout << p << "\n";
    return;
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