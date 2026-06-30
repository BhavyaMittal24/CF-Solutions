/*


digit dp : When you are trying to print all the numbers between L and R

prnt all the numbers less than <= d digits - no of digits in the number i <= d
 
cnt all the numbers less than<= d digits






*/


// in digit dp, bitmast dp : we can often use the recrsive dp to avoid evaluating the answer for unecessary states
// iterative dp is fastr
// think in terms of printing all the numbers

#include<bits/stdc++.h>
using namespace std;


// recursive backtrackign solution to generate all numbers less than euqal to d  digits
// we try to fill the d digit spaces for the number 
// and place diffferent digits there foriming the number and tracking it in the current Number
//
void printAllLessThanD(int idx, int n, int currNumber){

    // n digits are the max diguts and number is currNumber : using a dfs. back tracing solution
    // a1 a2 .... an : numbr = currNumber * 10 + a1 -> ... and steps continue in this order
    if( idx == n) {
        cout << currNumber << " ";
        return;
    }

    for(int d = 0; d <= 9; d++){
        printAllLessThanD(idx+1, n, currNumber* 10 + d);
    }
}

// eseense of counting and using dp
int cntLessThanDDigits(int idx, int n){

    // we dont need to use the currNumber now. Currnumber is out of scope for us
    // place n digits at n spaces and have 10 options each time
    if( idx == n){
        return 1;
    }

    int sum = 0;
    for(int d = 0; d <= 9; d ++){
        sum += cntLessThanDDigits(idx+1, n);
    }
    return sum;
}


void printLessThanN(int idx, int tight, int currNumber, string num){

    // 0 1 2  ......... n -1 digits
    // 3 4 2 5 6
    if(idx == num.size()){
        cout <<  currNumber  << " ";
        return;
    }

    int bound = (tight == 1) ? num[idx] - '0' : 9;

    for(int d = 0; d <= bound; d++){
        
        int newTight = tight && ( (num[idx] - '0') == d);
        printLessThanN(idx+1, newTight, currNumber* 10 + d, num);
    }
    return;
}

// total time complexity : recusrion hence very large : 10^n : where n is the no of dgitis in num
// same subproblem being solved again and again
int cntLessThanN(int idx, int tight, string num){

    if( idx == num.size()){
        return 1;
    }

    int bound = (tight == 1) ? num[idx] - '0' : 9;

    int sum = 0;
    for(int d = 0; d <= bound; d++){
        
        int newTight = tight && ( d == (num[idx] - '0'));
        sum += cntLessThanN(idx+1, newTight, num);
    }
    return sum;
}

int main(){

    int d;
    cin >> d;
    printAllLessThanD(0,d, 0);

    int cnt = cntLessThanDDigits(0,d);
    cout << cnt << "\n";

    string num;
    cin >> num;
    printLessThanN(0,1,0,num);

    cnt = cntLessThanN(0,1,num);
    cout << cnt << '\n';
    return 0;
}