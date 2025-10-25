#include<bits/stdc++.h>
using namespace std;

// return the count of numbers less than 123 : less than  a given number

//0-9_ _ _

// tight : it tells whether the bound is tight or not for the current option at the ith digit what all choices do i have?

// 123 : 1 -> 0/1/2

// 0 -> 0/1/2/..9

// 1234

// 10 -> i=2 , 0/1/..9

string num = "123";

// cnt of numbers less than 123
// dp[i][tight] : represent the count of numbers from ith digit to n-1 digit which have there prev i digits 
// The prev i digits if equals the prefix(0,i) for the string num, then tight is 1 

// log2(n) = no of digits
// tc : no of digits * 2 * 10
//  no of digtis * 2 * 10 <= 1e8
// d <= 5 * 1e7
int countLessThanN(int idx, int tight, int n){

    if(idx == num.length()){
        return 1;
    }

    int bound = (tight == 1) ? num[idx]-'0' : 9;

    int sum = 0;

    for(int i=0;i<=bound;i++){
        int isTight = tight & (i == (num[idx]-'0'));
        sum += countLessThanN(idx+1,isTight, n);
    }
    return sum;
}

// tc : can run this code for 10 ^ (100000000) .. 8 0s
int main(){

    int cnt = countLessThanN(0,1,3);
    cout << cnt << endl;
    return 0;
}