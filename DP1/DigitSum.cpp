// Problem Statement
// Find the number of integers between 
// 1 and K (inclusive) satisfying the following condition, modulo // 10^9 +7:

// The sum of the digits in base ten is a multiple of D.
// Constraints
// All values in input are integers.
// 1≤K<10 ^ 10000
 
// 1≤D≤100

// count of numbers between  1 and k where sum  of digits % d = 0 

#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

// i digits are set and n-i are rem and if prefix is matching, [0..i-1] then for the ith digit, i can have 
// num[i] choices only from 0

// f(i,tight)

// max sum = 10000*9 = 90000
// d = 10000  : 1e4 * 9*1e4 * 2

// sum % d == 0

long long dp[10001][2][101];

long long cntNumbers(int idx, int tight, int sumMade, string num, int D){
    if(idx == num.length()){
        if((sumMade % D == 0)) return 1;
        return 0;
    }

    if(dp[idx][tight][sumMade] != -1) return dp[idx][tight][sumMade];
    int bound = (tight == 1) ? num[idx]-'0' : 9;

    long long answer =0;
    for(int i=0;i<=bound;i++){
        int isTight = tight && (i == (num[idx] - '0'));
        answer = (answer + cntNumbers(idx+1, isTight, (sumMade + i) % D, num, D ))% mod; 
    }

    return dp[idx][tight][sumMade] = answer;
}

int main(){

    string K;
    int D;
    cin >> K;
    cin >> D;

    memset(dp,-1,sizeof(dp));

    long long ans = cntNumbers(0,1,0,K,D);
    cout << (ans -1 + mod) % mod << endl;
    return 0;
}