#include<bits/stdc++.h>
using namespace std;

int main(){


    int n, x;
    cin >> n >> x;

    // if( n ==x){
    //     cout << "Yes\n";
    //     for(int i = 1; i <= 2*n - 1; i ++){
    //         cout << i << "\n";
    //     }
    //     return 0;
    // }

    if( x == 1 || x == (2*n - 1) ) {
        cout << "No\n";
        return 0;
    }

    vector<int> arr( (2*n)-1,0);

    set<int> st;

    int l = x-2;
    int h = x+1;

    if(x != 2){
        arr[n-1] = x;
        arr[n-2] = x-1;
        arr[n] = x+ 1;
        arr[n+1] = x-2;
        l = x-2;
        h = x+1;
    }

    else {
        arr[n-1] = 2;
        arr[n-2] = 3;
        arr[n] = 1;
        arr[n+1] = 4;
        l = 1;
        h = 4;
    }

    int num = 1;
    cout << "Yes\n";
    for(int i = 0; i < 2*n-1; i ++){

        if(arr[i] != 0) continue;
        if( num >= l && num <= h) num = h+1;

        arr[i] = num;
        num++;
    }


    for(auto x : arr){
        cout << x << "\n";
    }
    return 0;
}