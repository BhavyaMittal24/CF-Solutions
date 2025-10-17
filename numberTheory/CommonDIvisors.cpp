#include<bits/stdc++.h>
using namespace std;

// ai can be <= 1e6
// n can be 2*1e5
// gcf can be between 1 to 1e6
// for thr factors 1 to 1e6, the largest factor having  numbers  >=2 of whom it is a factor is gcd
// iterate over all factors from 1 to 1e6 and check how many numbers are multiple of it, if >=2 largest factor is the ans

// lagest factor which is a factor of alteast 2 nubers is the gcd

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi=0;
    //set<int> st;
    vector<int> factors(1e6+1,0);
    int maxGCD = 1;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        factors[a[i]]++;
        maxi = max(maxi,a[i]);
    }

    // check for all possible factors and see whcihc has count >=2 and is largest

    for(int i=maxi;i>=2;i--){
        int cnt = 0;
        for(int j=i;j<=maxi;j+=i){
            cnt += factors[j];
            if(cnt >= 2){
                maxGCD = max(maxGCD,i);
            }
        }
        
    }
    cout << maxGCD << endl;
    return 0;
}

