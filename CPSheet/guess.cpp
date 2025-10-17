// x is between 1 and n

// guess the number x with min questions
// questions are is is x divisible by ai?

// a1 … ak 

// if x is divisible by ai, then it is also divisible by all factors of ai

#include<bits/stdc++.h>
using namespace std;

set<int> solve(){
 
  int n;
  cin >> n;
  // x is between 1 to n
  vector<int> possibleFactors(n+1,0);
  set<int> a; 
  for(int i=2;i<n;i++){
     int questionNumber = i;
     if(possibleFactors[i] == 1) continue;
     if(n % i==0){
        while( n % questionNumber == 0){
          a.insert(questionNumber);
          //if( n == questionNumber) return a;
          questionNumber = questionNumber*questionNumber;
        }
        if(questionNumber <= n) a.insert(questionNumber);
     }

     // if not divisible by prime, then don't ask questions for other factors for that prime too.
     else {
         for(int j=i*i;j<=n;j+=i) possibleFactors[j] = 1;
         a.insert(i);
     }
  }
    return a;
}

int main(){
    set<int> a = solve();
    cout << a.size() << endl;
    for(auto it : a) cout << it << " ";
    cout << endl;
    return 0;
}