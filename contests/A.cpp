// solved using greedy


#include<bits/stdc++.h>
using namespace std;

void solve(){

   int n;
   cin >> n;
   
   int matches = 0;
   int loserTeams = 0;
   while(n > 1) {
      matches = matches + n/2;

      if(n % 2) {
        n = n/2+1;
      }
      else {
         n = n/2;
      }
   }

    loserTeams = matches;
   while(loserTeams > 1) {
      matches += loserTeams/2;
      if( loserTeams % 2) {
         loserTeams = loserTeams/2 +1;
      }
      else loserTeams = loserTeams/2;
   }
   // add 1 for final match
   cout << matches+1 << endl;

}

int main(){

  int t; 
  cin >> t;
  while(t--){
    solve();
   }
  return 0;
}