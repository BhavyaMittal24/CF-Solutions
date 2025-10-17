// count good subarryas


// no of elements = sum of elements

// a good subarray = sum of elements - number of elements = 0;


// p0 p1 p2 ..       pi … pn

// 0   2   0   2   0 

#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  long long sum = 0;
  long long cnt = 0;
  unordered_map<long long,long long> mp;
  for(int i=0; i<n;i++){
    sum += s[i] - '0';
    sum -= 1;
    if(sum == 0) cnt ++;
    // if there are prev occurences of same same it means pre[r] = pre[l-1]
    cnt += mp[sum];
    mp[sum]++;
  }
    cout << cnt << endl;
  return;
  
}

// 0 1 -1

// 0 1 0


int main()
{
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}