#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    int n,m,s, wa, wb;
    cin >> n >> m >> s >> wa >> wb;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<long long> prefixSumA(n+1,0);
    vector<long long> prefixSumB(m+1,0);
    for(int i=1;i<=n;i++) prefixSumA[i] = prefixSumA[i-1] + a[i-1];
    for(int i=1;i<=m;i++) prefixSumB[i] = prefixSumB[i-1] + b[i-1];
    long long maxCost = 0;

    // select number of elements from a = i
    for(int i=0;i<= min(n,s/wa);i++){
        long long weightFromA = i*wa;
        long long weightFromB = s - weightFromA;
        long long j = min(1ll*m, weightFromB/wb);
        long long currentCost = prefixSumA[i] + prefixSumB[j];
        maxCost = max(maxCost, currentCost);
    }
    cout << maxCost << endl;
    return 0;
}