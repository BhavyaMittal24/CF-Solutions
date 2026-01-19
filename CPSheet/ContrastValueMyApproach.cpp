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


void solve(){

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    // replace the subarray a1, a2 .. ak where ai <= ai+1 with a1, ak 
    int cnt = 1;

    int dir = 0;
    // dir = -1 : ai-1 > ai
    // dor = 1 : ai-1 < ai
    for(int i = 1; i < n; i ++){
        if(a[i-1] < a[i]){
            if(dir != 1) {
                cnt++;
            }
            dir = 1;
        }
        else if(a[i-1] > a[i]){
            if(dir != -1){
                cnt++;
            }
            dir = -1;
        }
    }
    cout << cnt << "\n";
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



