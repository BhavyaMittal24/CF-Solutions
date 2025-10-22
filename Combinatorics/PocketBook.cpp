#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<char>> strings(n,vector<char>(m));
    const long long mod = 1e9 + 7;
    long long ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> strings[i][j];
        }
    }

    for(int j=0;j<m;j++){
        set<char> unique_chars;
        for(int i=0;i<n;i++){
            unique_chars.insert(strings[i][j]);
        }
        ans = (ans * unique_chars.size()) % mod;
    }

    cout << ans << endl;
    return 0;
}