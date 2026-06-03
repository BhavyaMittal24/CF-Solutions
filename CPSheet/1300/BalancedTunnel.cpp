#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 0; i < n; i ++) cin >> b[i];

    int i = 0;
    int j = 0;

    int cnt = 0;

    vector<int> vis(n,0);

    while(i < n && j < n){

        while( ( vis[a[i]] == 0)  && j < n){

            vis[b[j]] = 1;
            if(b[j] != a[i]) cnt++;
            j++;
        }
        i++;
    }

    cout << cnt << '\n';
    return 0;
}