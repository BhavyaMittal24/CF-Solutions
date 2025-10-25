#include<bits/stdc++.h>
using namespace std;

// tc: backtracking code : no of problems : 0(10^n) * n
void generateNumbers(int idx, int n, int numberMadeSoFar){
    if(idx == n) {
        cout << numberMadeSoFar << endl;
        return;
    }
    for(int i=0;i<10;i++){
        // new number formed : numberMadeSoFar* 10 + i
        // 2, 12 : 12*2 + [0,9]
        generateNumbers(idx+1,n, numberMadeSoFar* 10 + i);
    }
    return;
}

// now count the no of numbers having n digits
// this can be optimized via dp where i can store the result
// dp[i] = cnt of no of numbers from ith digit to n-1th digit when first i digits are set already/
// cnt of number having n-i dgits

int cntNumber(int idx, int n){
    if(idx == n){
        return 1;
    }
    int sum = 0;
    for(int i=0;i<10;i++){
        sum += cntNumber(idx+1,n);
    }
    return sum;
}
int main(){

    // function to print all the numbers for digits = n
    int n;
    cin >> n;
    cout << cntNumber(0,n) << endl;
    generateNumbers(0,n,0);

    vector<int> dp(n+1,0);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        dp[i] = 10*dp[i+1];
    }
    cout << dp[0] << endl;
    return 0;
}