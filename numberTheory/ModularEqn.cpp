#include<bits/stdc++.h>
using namespace std;

int main(){

    long long a,b;
    cin >> a >> b;

    // find solution to a % x = b

    // x >= b+1
    // x is a factor of (A-B)

    if( a < b) {
        cout << "0" << endl;
        return 0;
    }

    if(a == b){
        cout << "infinity" << endl;
        return 0;
    }

    long long count = 0;
    for(int i=1;i*i <= a-b;i++){
        if( (a-b) % i == 0){
            if(i > b) count++;
            if( (a-b) / i != i && (a-b) / i > b) count++;
        } 
    }

    // for 36, 6 is a factor, but not 2 times, we only count 6 once. when i = n/i
    cout << count << endl;
    return 0;
}