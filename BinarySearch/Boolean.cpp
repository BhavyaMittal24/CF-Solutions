#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    // 1 = True;
    // 0 = false;


    int low = 0;
    int high = n-1;

    int mid =0;

    // l       m-1 mid m+1         h
    // T T T T T F F F F T T T F

    // 1 1 1 1 1 1 1 1 1 

    // return any index which has a true followed by an F
    while(low <= high){
        mid = low + (high - low)/2;
        if( mid < n-1 && a[mid] == 1 && a[mid+1] == 0){
            cout << mid << endl;
            return 0;
        }
        if(mid > 0 && a[mid]== 0 && a[mid-1]==1){
            cout << mid-1 << endl;
            return 0;
        }

        if(a[low] == 1 && a[mid]==0){
            high = mid;
        }
        else {
            low = mid+1;
        }
    }

    cout << -1 << endl;
    return 0;

}


// [1 1 1 0]  [0 1 1 1 0]  [1 0 1 0] 
// [1 1 0   1] [1 1][ 0 0] [ 0 1  1   1  0]