#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    long long ans = 0;

    vector<long long> factorials(n+1,1);

    for(int i=1;i<=n;i++){
        factorials[i] = (factorials[i-1] * i) % m;
    }

    for(int i=1;i<=n;i++){
        int segments = n -i +1;
        long long ways = segments * factorials[i] % m;
        ways = (ways * factorials[n - i]) % m;
        ways = (ways * segments) % m;
        ans = (ans + ways) % m;
    }
    cout << ans << endl;
    return 0;
}