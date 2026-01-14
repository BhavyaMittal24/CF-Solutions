#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    // arra y storing the friends on day i and the day i
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int>> c(n);

    for(int i = 1; i <= n; i ++){
        int friends;
        cin >> friends;
        a[i-1] = {friends, i};
    }

    

    for(int i = 1; i <= n; i ++){
        int friends;
        cin >> friends;
        b[i-1] = {friends, i};
    }

   

    for(int i = 1; i <= n; i ++){
        int friends;
        cin >> friends;
        c[i-1] = {friends, i};
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

     sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    long long maxCnt = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k ++){  

                int x = a[i].second;
                int y = b[j].second;
                int z = c[k].second;

                //cout <<  i << " " << j << " " << k << " " << " { "  << a[i].first << ", " <<  a[i].second << " }, { " << b[j].first <<  ", " << b[j].second << "}, { " << c[k].first << "," << c[k].second << " } \n"; 
                long long val =  a[i].first + b[j].first + c[k].first;
                if( (x != y) && (y != z) && (x != z)) maxCnt = max(maxCnt,val );
            }
        }
    }

    cout << maxCnt << "\n";
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