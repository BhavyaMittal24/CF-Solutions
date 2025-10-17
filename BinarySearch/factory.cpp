#include<bits/stdc++.h>

using namespace std;

bool isPossibleToMake(vector<int> &efficency, long long k, long long desiredTime) {
   long long products = 0;
   for(auto &e : efficency) {
        products += desiredTime / e;
        if (products >= k) return true; 
    }
    return false; // Not enough products can be made
}
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> efficency(n);
    int minElement = 1e9;
    for(int i = 0; i < n; i++){
        cin >> efficency[i];
        minElement = min(minElement, efficency[i]);
    }

    long long low =0;
    long long high = minElement * k;
    long long ans = 1e18;
    long long mid = 0;
    // FFFFFFFFFFFFTTTTTTTTTTTTTTTTTTT
    while( low <= high){
        mid = (low+high)/2;
        if(isPossibleToMake(efficency, k, mid)){
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }
    cout << ans << endl;
    return 0;
}