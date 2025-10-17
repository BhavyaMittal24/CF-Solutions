
#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long binaryExp(long long base, long long exp){

  long long ans = 1;
  base = base % mod;
  while(exp > 0) {
     if(exp & 1) {
       ans=  ( ans * base ) % mod;
     }
     base = (base * base) %  mod; 
     exp = exp >> 1;
  }
  return ans;

}
int main(){


  string s;
  cin >> s;
  
  int n = s.length();

  vector<long long> factorial(n+1,1);

  for(int i=1;i<=n;i++){
     factorial[i] = ( factorial[i-1] * i) % mod;
  }

  map<char,int> mp;
  for(int i=0;i<n;i++){
    mp[s[i]] ++;
  }
  long long ans = factorial[n];
  for(auto it : mp) {
    long long freq = it.second;
    long long power = factorial[freq];
    ans = ( ans * binaryExp(power, mod-2) ) % mod;
  }
  cout << ans << endl;

  return 0;
}