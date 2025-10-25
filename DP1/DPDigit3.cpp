#include<bits/stdc++.h>
using namespace std;

// return the count of numbers between L and R (  1<= l,r <= 10 ^ 1e8)
// where odd indexes have odd digits and even indices have even digits

// dp[i][tight][isValid] : 


// fn that returns the cnt of all numbers less than num satisfying the conditon

// instead of isValid you can store a bitmast representing 0,1 : where 0 means incorrect index, 1 means correct
long long cntLessThan(int i, int tight, int isValid, string num){
    if( i == num.length()){
       if(isValid) return 1;
       return 0;
    }

    int bound = (tight == 1) ? num[i] - '0' : 9;
    long long sum = 0;
    for(int d=0;d<=bound; d++){
        int isTight = (tight && (d == (num[i]- '0')) );
        int isDigitValid = isValid && ( (d % 2) == (i % 2));
        sum += cntLessThan(i+1,isTight,isDigitValid, num);
    }
    return sum;
}

int check(string num){
    int ans = 1;

    for(int i=0;i<num.length();i++){
        int d = num[i] - '0';
        if( (d % 2) != (i %2)) return 0; 
    }
    return 1;
}
int main(){

    string R = "100";
    string L = "1";
    long long lessThanR = cntLessThan(0,1,1,R);
    long long lessThanL = cntLessThan(0,1,1,L);
    cout << lessThanR - lessThanL + check(L) << endl;
    return 0;

}
// 1, 2, 3, 4, 5 , 6, 7 ,8 ,9,10,11