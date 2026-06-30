#include<bits/stdc++.h>
using namespace std;

/*
n = 2^k players are playing matches between each other
1 2 3 4 ..... 2^k

n-> n/2 -> b/4 //// ... 1 winner


*/

// final -> only one player from left half and one from right half
vector<double> knockoutProb(int L, int R, vector<vector<double>>& p){

    vector<double> winningProbAtStage;
    if( L == R){
        // leaf node : a single player : prob of winning against themself = 1
        winningProbAtStage.push_back(1.0);
        return winningProbAtStage;
    }

    int mid = (L+R)/2;
    // prob of all player numbers L to mid reaching the previous
    vector<double> left_prob = knockoutProb(L, mid, p);
    // from mid +1 to R reachign this round 
    vector<double> right_prob = knockoutProb(mid+1, R, p);

    // the winner can be only 1 : but since it is probabilistic : the ,atch will be between
    // one player from left and one from right

    // from L to R

    // 1, 4 : left : size = 4 : 0 to 3 index 
    // 5,8 : right
    for(int i = 0; i < left_prob.size() ; i ++){
        int playerLeft = i + L;

        double playerRightReachingAndLosing = 0;
        for(int j = 0; j < right_prob.size(); j ++){
            int playerRight = j + mid+1;
            double probReachingPre = right_prob[j];
            playerRightReachingAndLosing += probReachingPre * p[playerLeft][playerRight];
        }
        double playerLeftWinning = left_prob[i] * playerRightReachingAndLosing;
        winningProbAtStage.push_back(playerLeftWinning);
    }

    for(int i = 0; i < right_prob.size() ; i ++){
        int playerRight = i + mid+1;

        double playerLeftReachingAndLosing = 0;
        for(int j = 0; j < left_prob.size(); j ++){
            int playerLeft = j + L;
            playerLeftReachingAndLosing += 1.0* left_prob[j] * p[playerRight][playerLeft];
        }
        double playerRightWinning = right_prob[i] * playerLeftReachingAndLosing;
        winningProbAtStage.push_back(playerRightWinning);
    }
    return winningProbAtStage;
} 

int main(){

    int k;
    cin >> k;
    long long n = pow(2,k);
    
    vector<vector<double>> p(n+1, vector<double> (n+1,0));
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            cin >> p[i][j];
            // prob of i winnig over j
            p[j][i] = 1.0 - p[i][j];
        }
    }

    // 1,0 is p[i][j]

    vector<int> players;
    for(int i =1; i <= n; i ++){
        players.push_back(i);
    }
    // 1 2 3 4 .... 16

    while(players.size() != 1){
        vector<int> winners;
                       
        // 1 2 3 4 5 6 7 8
        for(int i = 0; i < players.size(); i += 2){
            int p1 = players[i];
            int p2 = players[i+1];

            if(p[p1][p2] == 1){
                // p1 will win against p2
                winners.push_back(p1);
            }
            else {
                winners.push_back(p2);
            }
        }
        players = winners;
    }

    vector<double> ans = knockoutProb(1, n, p);
    // detemrin the winner :
    cout << players[0] << endl;

    for(auto it : ans) {
        cout << it << " " ;
    }

    return 0;
}