#include<bits/stdc++.h>
using namespace std;


// dp[i][l][sl] : no of min operations required to make all pleters act optimally from i to n-1

// Time taken for the problem : no of unqiue subproblems * time for each each subprobkem
// obverlapping : 2 options : 0 (2 ^ n-2) 
// 0( n * 4) * 4 

int moves(int i, int l, int sl, string s, int s0, int s1,  vector<vector<vector<int>>>& dp){
    int changes = 5e5;
    int n = s.length();

    if( i == n-1){
        // placing left : 0 at n-1
        if ( ( l != 0 || sl != 0 ) && (s0 !=0 || s1 !=0) && (l !=0 || s0!= 0)){
            int cnt = (s[i] == 'L') ? 0 : 1;
            changes = min(changes, cnt);
        }
        

        // placing right : 1 at n-1
         if ( ( l != 1 || sl != 1 ) && (s0 !=1 || s1 !=1) && (l !=1 || s0!= 1)){
            int cnt = (s[i] == 'R') ? 0 : 1;
            changes = min(changes, cnt);
        }

        // else both conditions are not possible
        // min possible no of ways is max : impossible 
        return changes;
    }

    if(dp[i][l][sl] !=-1) return dp[i][l][sl];
    // based on l, sl , I can choose to place the ith element and count the no of flips

    // i is R 

    int placeRight = n;
    if(l != 1 || sl != 1){
        placeRight = (s[i] == 'R') ?  0 : 1;
        placeRight += moves(i+1, 1, l, s, s0,s1, dp); 
    }

    int placeLeft = n;
    if( l != 0 || sl != 0){
        placeLeft = (s[i] == 'L') ? 0 : 1;
        placeLeft += moves(i+1, 0, l, s, s0, s1, dp);
    }
    return  dp[i][l][sl] = min(placeLeft, placeRight);
}


void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n;
    // memset(dp,-1,sizeof(dp));
    // int ans = n;
    // int cntA = 0;

    // // RR
    // if(s[0] == 'L') cntA ++;
    // if(s[1] == 'L') cntA ++;
    // cntA = cntA + moves(2,1,1, s, 1, 1);

    //   memset(dp,-1,sizeof(dp));
    // int cntB = 0;
    // // RL
    // if(s[0] == 'L') cntB ++;
    // if(s[1] == 'R') cntB ++;
    // cntB = cntB + moves(2,0,1, s,1,0);

    //   memset(dp,-1,sizeof(dp));
    // int cntC = 0;
    // // LR
    // if(s[0] == 'R') cntC ++;
    // if(s[1] == 'L') cntC ++;
    // cntC = cntC + moves(2,1,0, s,0,1);

    //   memset(dp,-1,sizeof(dp));
    // int cntD = 0;
    // // LL
    // if(s[0] == 'R') cntD ++;
    // if(s[1] == 'R') cntD ++;
    // cntD = cntD + moves(2,0,0, s, 0,0);

    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            
            int cnt1 = (i == 0) ? s[0] != 'L' : s[0] != 'R';
            int cnt2 = (j == 0) ? s[1] != 'L' : s[1] != 'R';

            vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int> (2,-1)));
           
            ans = min (ans, moves(2,j,i, s, i, j, dp) + cnt1 + cnt2);
        }
    }
  
    cout << ans << endl;

}
int main(){


    int t;
    cin >> t;
    while(t--){
        solve();
    }
}