#include<bits/stdc++.h>
using namespace std;


int main(){
    string a;
    string b;
    // length of b < len(A)
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    long long cntOnesInA = 0;
    long long cntOnesInB = 0;
    long long totalCnt = 0;
    for(int i=0;i<m;i++){
        if(b[i] == '1') cntOnesInB++;
    }
    for(int i=0;i<n;i++){
        if(a[i] == '1') cntOnesInA++;
        if( i>=m){
            if(a[i-m] == '1') cntOnesInA--;
        }
        if(i>=m-1){
            if( cntOnesInA % 2 == cntOnesInB % 2){
                totalCnt++;
            }
        }
    }
    cout << totalCnt << endl;
    return 0;
}