#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    int cntZero =0;

    for(int k = 0; k < n; k ++){
        if( s[k] == '0') {
            cntZero++;
        }
    }


    if( cntZero == 0){

        cout << "DRAW\n";
    }

    else if(cntZero == 1){
        cout << "BOB\n";
    }

    else if( cntZero % 2 == 0){
        cout << "BOB\n";
    }

    // odd number of 0s
    else if( cntZero % 2 == 1){
        cout << "ALICE\n";
    }
    // for(int k = n-1; k >= 0; k --){
    //     if(s[k] == '0'){
    //         j = k;
    //         break;
    //     }
    // }

    // // s is a palindrome intially

    // if( i == -1 || j == n) {
    //     cout << "DRAW\n";
    //     return;
    // }

    // else if ( i == j){
    //     // kust a single 0
    //     cout << "BOB\n";
    //     return; 
    // }

    // // get to i and j and perform operations

    // vector<int> moves(2,0);

    // // min cost 



    // int turn = 0;

    // if( (n % 2 == 1) && s[n/2] == '0'){
    //     moves[0]++;
    //     s[n/2] = '1';
    //     turn = 1;
    // }
    // bool rev = false;
    // int currIdx = i;


    // while( i <= j){

    //     // when palindrome 
    //     bool cond1 = (i == (n-1-j)) && (s[i] == s[j]) && (s[i] == '0');

    //     bool cond2 = (i != (n-1-j)) && (rev == true);

    //     //cout << i << " " << j << "\n";
    //     if( cond1 || cond2 ){

    //         s[currIdx] = '1';

    //         if(currIdx == i){
    //             while(i < n && s[i] == '1'){
    //                 i++;
    //             }
    //             currIdx = j;
    //         }

    //         else{
    //             while(j >= 0 && s[j] == '1') j--;
    //             currIdx = i;
    //         }

    //         moves[turn]++;
    //         rev = false;
    //         // prev operation is not reverse
    //     }

    //     else if( (i != (n-1-j)) && rev == false){
    //         rev = true;
    //     }

    //     turn = turn ^ 1;
    // }

    // if( moves[0] == moves[1]){
    //     cout << "DRAW\n";
    // }
    // else if(moves[0] < moves[1]){
    //     cout << "ALICE\n";
    // }

    // else {
    //     cout << "BOB\n"; 
    // }

    return;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}