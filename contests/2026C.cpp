#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long>& a, pair<long long, long long> &b)
{
    return abs(a.first - a.second) > abs(b.first - b.second);
}

void solve(){

    int n;
    cin >> n;
 
    vector<int> arr(n+1,0);

    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }

    vector<int> op;

    int i = n;

    int flips = 0;
    while( i>=1){

      
        // find first index which is positive
        int j = i;
        int val = arr[j];
        if(flips % 2 == 0 ) val = arr[j];
        else val = -1* arr[j];
        while( j >= 1 && val < 0){
            j--;
            if(flips % 2 == 0 ) val = arr[j];
            else val = -1* arr[j];
        }

        // j is the value where we have first positive;
        if(j != 0) op.push_back(j);
        flips++;
        i = j;
    }

    cout << op.size() << "\n";

    for(auto it : op){
        cout << it << " ";
    }

    cout << "\n";

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