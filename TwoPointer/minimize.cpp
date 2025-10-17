#include<bits/stdc++.h>
using namespace std;


// 2 6 4 5
void solve() {
  string s;
  cin >> s;
  string even = "";
  string odd= "";
  for(auto i: s){
     if( i %2 == 0) even += i;
     else odd += i;
  }

  int i = 0;
  int j = 0;
  string ans="";
  while ( i < even.length() && j < odd.length()){
	if(even[i] - '0' < odd[j] - '0'){
        ans+=(even[i]);
        i++;
    }
    else {
        ans+=(odd[j]);
        j++;
    }
  }

 while(i < even.length()){
    ans+=(even[i]);
    i++;
 }

 while(j < odd.length()) {
    ans+=(odd[j]);
    j++;
 }
 cout << ans << endl;
}
int main(){

  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}