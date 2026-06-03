#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    vector<int> arr(n,0);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int med = arr[n/2];

    /// arr : 7, 2, 1,3,5,6,7,9 ,11, 13
    
    // Make all elements the same : ? can select 2 at one time and make them same a,b :  min(a,b) <= x <= max(a,b)

    // for each i, make the all elements same as 7 :
    // cnt all elements < 7 and cnt all > 7 :  5nos > 7 and 2 nos < 7 : 
    //  b1 b2  7  a1 a2 a3 a4 a5
    // max(> 7, < 7)
    // we need to find the min across all these max(> x, < x)


    // for  the median element, the no of elements > median and no of elements <median will be very less
    // max(no of elements > median, no < median ) will be Least
   
    // when we want to to converge a set of elements : sort and try to converge the mto median at a min cost
    // a1 a2 a3 .... median ai ai +1 .... an

    // cnt elements > median and cnt elements < median : max() of these two 
    // but the max will be miniumum
    
    int cntLess = 0;
    int cntMore = 0;

    for(int i = n/2 +1; i < n; i++){

        if(arr[i] != med){
            cntMore = n -i;
            break;
        };
    }

    for(int i = n/2 - 1; i >= 0; i--){

        if(arr[i] != med){
            cntLess = i +1;
            break;
        }
    }

    cout << max(cntLess, cntMore) << "\n";
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