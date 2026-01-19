//a ; a1, a2, ... an 

// form an array b which is the subsequence of array a where 
// contrast value is same 

// max size of array b = n, same as array a
// min size of array b can be 1 when the contrast value is 0 for the array a : 1,1,1,1
// contrast value of [x] = 0
// min size other than this can be 2 when the b = [b1, b2] where b1 - b2 = contrast value of a


// contrast value of a would be in long long

// min possible size of b ?

// brute force : seach for all possible sizes and check : all subarrays min sizes from 1 to n 

// to check for all subarrays of size k : it would take n*n complecity

// use binary search on answer : for a subarray of size k : is it possible to have a contrast value in that wondow : use slidig window
// [ a1 a2 a3 a4 a5]  : k = 3

// + (a4 - a3) - ( a2-a1)

#include<bits/stdc++.h>
using namespace std;

// check if possible to have any one subarray of fixed size mid which has the same contrast value as a
bool check(long long contrastVal, vector<int>& a, int k){

    int n = a.size() -1;
    bool isPossible = false;

    long long cVal = 0;
    for(int i = 2; i <= n ; i ++){
        cVal += abs(a[i] - a[i-1]);

        if( i > k){
            cVal -= (abs( a[i - k] - a[i-k + 1]));
        }

        if( i >= k){
            if(cVal == contrastVal) isPossible = true;
        }
    }
    return isPossible;
}

void solve(){
    int n;
    cin >> n;

    long long contrastVal = 0;
    vector<int> a(n+1);
    for(int i = 1 ; i <=n; i ++){
        cin >> a[i];
    }

    for(int i = 2 ; i <= n ; i++){
        contrastVal  +=  abs( a[i] - a[i-1]);
    }

    // check for the min possuble size for the array b

    int minSize = 0;

    int low = 1;
    int high = n;

    int mid;

    while( low <= high){
        mid = (low + high) /2;

        // check if possible to have a contrast value
        if( check(contrastVal, a, mid) ){
            minSize = mid;
            high = mid-1;
        }
        else {
            low = mid +1;
        }
    }

    cout << minSize << "\n";
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



