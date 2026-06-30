// Count the numbers between L and R : L <= num <= R where at even indices even digits are placed and at odd indices odd numbers are placed

#include<bits/stdc++.h>
using namespace std;

int dp[100][2][100];

//            tight or not no has started or not, ie placed some digit or not, and what is the index parity : first parity would be 1, next would be 0

// 0 1 2 3 ............i-1 i : tight, start, pairity
// where start is whether if number has started orn ot
// parity is the paroty for the number index whtever number has been so for formed
// intiially for the first one it would be 1
int cntLessThanNEvenOddIndices(int idx, int tight, int start, int parity, string num){

    if( idx == num.size() ){
        // went ahead across all the n digits
        if( start == 0) return 0;
        return 1;
    }

    int bound = (tight == 1) ? num[idx] - '0' : 9;

    int sum = 0;
    for(int d = 0; d <= bound; d ++){

        int newTight = tight && (( num[idx] - '0') == d );

        if( !start){

            if( d == 0){
                sum += cntLessThanNEvenOddIndices(idx+1, newTight, start, parity, num);
            }

            else {
                if( d % 2 == parity){
                sum += cntLessThanNEvenOddIndices(idx+1, newTight, 1, parity^ 1, num);
            }
            }
        }

        else {
            // only place same parity number at that index for the number
            if( d % 2 == parity){
                sum += cntLessThanNEvenOddIndices(idx+1, newTight, 1, parity^ 1, num);
            }
        }
    }

    return sum;
}




int cntLessThanN(int idx, int tight, int currIdx, string num, int currNumber){

    if(idx == num.size()){
        //cout << currNumber << " ";
        // we will reduce 1 as 0 will be counted but we dont want to add it as 0,1 will not be counted as 0 at 1st index is
        
        if(currIdx == 1) return 0; // no number started yet
        return 1;
    }
    // 0 1 2 3 .......n -1 digits need to be placed
    // currIdx = 1 : the index for the number formed so far
    // no digit placed if 0 gets placed. issue for trailing zeroes

    if( dp[idx][tight][currIdx] != -1) return dp[idx][tight][currIdx];

    int bound = (tight == 1) ? (num[idx] - '0') : 9;
    int sum = 0;
    
    // currIdx = 1, when not started
    // when placing for the first time we have it as 1, which later becomes 2;
    for(int d = 0; d <= bound ; d++){

        // plain 0 will not bi ncluded in thus as 0 is a n even numbe rat off index
        if( (d == 0) && (currIdx == 1) ){
            // first index and i want to place 0 there : trailing zeroes
            sum += cntLessThanN(idx+1, 0, currIdx, num, currNumber);
        }
        
        else {
            int newTight = tight && ( (num[idx] - '0') == d );
            if(currIdx % 2 == d % 2){
                sum += cntLessThanN(idx+1, newTight, currIdx+1, num, currNumber* 10 + d);
            }
        }

    }
    return dp[idx][tight][currIdx] = sum;
}

// tc : dp[idx][tight][currIdx] : d * 2 * d * 10 : 20 *d^2 <= 1e8


int main(){

    memset(dp, -1, sizeof(dp));
    string num;
    cin >> num;
    int cnt = cntLessThanN(0,1,1,num,0);
    cout << cnt << '\n';

    cnt = cntLessThanNEvenOddIndices(0, 1, 0, 1, num);
    cout << cnt << '\n';
    return 0;
}