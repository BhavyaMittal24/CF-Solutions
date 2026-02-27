#include<bits/stdc++.h>
using namespace std;

// i + j = ai. aj

//cnt of all pairs of i,j where i < j 

// ai . aj < 2n
// no of possivle values for these : xlogx pairs

// { ai, i} , {aj ,j}
// x.y < 2n
// x = 1, x = 2 ... x = 2-1 : find all these values of y

// x = ai : check for all values for aj (j > i) where aj < 2n

// 1.........i  ..  j ..... n

// i -> ai is distinct unique ai for each i : ai < 2n

// sort based on value : all pairs x . y < 2n
// chose value for x 
// x and then y < 2n/x : and check if val indx x + val idx y = x.y  -> +1

void solve(){

// find all pairs x,y where x.y < 2n for that both x,y < 2n

// for each possible value x, y  pair ensure that idx[x] + idx[y] = x.y +1

    int n;
    cin >> n;

    vector<int> arr(n+1);

    vector<pair<int,int>> pairs;
    for(int i = 1; i <= n; i ++) {
        
        cin >> arr[i];

        // arr[i] should be less than 2n
        // 1 <= i+j <= 2n-1
        if(arr[i] >= 2*n) continue;

        // val, idx
        pairs.push_back({arr[i], i});
    }

    sort(pairs.begin(), pairs.end());

    // sorted basef on value

    long long cnt = 0;

    // a4, .. a6 .... a8 .... x .... y
    for(int i = 0; i < pairs.size(); i ++){

        int x = pairs[i].first;
        
        // go to next bigger : x +1, ... 2n-1
        // check all possible valus of y here
        for(int j = i+1; (j < pairs.size()) && ((1ll*x * pairs[j].first) < 2ll*n) ; j ++){
            
            int y = pairs[j].first;

            if( 1ll*x* y  == (pairs[i].second + pairs[j].second)) cnt++;
        } 
    }
    cout << cnt << "\n";
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}