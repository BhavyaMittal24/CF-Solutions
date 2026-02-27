#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n , m;
    cin >> n >> m;
    vector<int> infected(m,0);

    for(int i = 0; i < m; i ++){
        cin >> infected[i];
    }

    sort(infected.begin(), infected.end());

    vector<int> gaps;

    // n ~ 1e9
    // m <= 1e5

    for(int i = 1; i < m; i ++ ){
        // m[i] - m[i-1]
        gaps.push_back(infected[i] - infected[i-1] - 1);
    }

    // we select the largest gap, because in 2 days, I can save the largest gap of uninfected people : gap-2 is saved
    gaps.push_back(n - infected[m-1] + infected[0] - 1);

    // sort in the reverse order
    sort(gaps.rbegin(), gaps.rend());

    int days = 0;
    int numSaved = 0;
    for(auto gap : gaps){
        gap = gap - 2*days;

        if( gap > 0){
            numSaved++;
            gap -= 2;
            days++;
        }

        if(gap > 0){
            numSaved += gap;
            days++;
        }
    }

    cout << n - numSaved << endl;
    return;

}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}