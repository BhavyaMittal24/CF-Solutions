#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> grid(n);
    // grid of n strings of size n

    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        grid[i] = s;
    }

    // for each spiral traversal : I want the entrie array and for that each a[i] = a[i] + n - 1


    int top = 0;
    int bottom = n-1;

    int left = 0;
    int right = n-1;

    int square = n;

    int cnt = 0;

    while( top <= bottom && left <= right && square > 0){

        // cout << top << " " << left << " " << bottom << " " << right << "\n";
        string arr = "";

        for(int i = left; i <= right; i++){
            arr += grid[top][i];
        }
        top++;
        
        for(int j = top; j <= bottom; j++){
            arr += grid[j][right];
        }

        right--;

        for(int i = right; i >= left; i --){
            arr += grid[bottom][i];
        }
        bottom--;

        for(int j = bottom; j >= top; j --){
            arr += grid[j][left];
        }
        left++;

        vector<pair<int,int>> cnt01(square-1, {0,0});

        for(int i = 0; i < square-1; i ++){

            int cnt0 = 0;
            int cnt1 = 0;

            for(int j = 0 ; j <= 3 ; j++){

                int idx = i  + j*(square - 1);
             
                if(arr[idx] == '0') {
                    cnt0++;
                }

                if( arr[idx] == '1'){
                    cnt1 ++;
                }
            }

            cnt01[i] = {cnt0,cnt1};
            
            int diff = 4 - max(cnt0, cnt1);
            cnt += diff; 
        }

        square -=2;
    }

    cout << cnt << "\n";

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