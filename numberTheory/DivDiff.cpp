// divisibility of a difference


// n

// k elements such that all kc2 have a diff % m = 0
//  (ai - aj) % m = 0
// ai - aj is a factor of m
// ai : aj = ai + km where k is {0,1,2..} k>= 0 and I

// ai % m = ai % m

// map which stores the list of elements for a given remainder
// if the count of elements >=k , return
#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  int k;
  int m;
  cin >> n >> k >> m;
 // map containing rem and the list of values which support that remainder
  // eg : 0 : {1,4,5,6} for m = 1
  map<int, vector<int>> mp;
  int rem = -1;
  multiset<int> ms;
  for(int i=0;i<n;i++) {
     int x;
     cin >> x;
     ms.insert(x);
     mp[x%m].push_back(x);
     if(mp[x%m].size() >= k) {
	     rem = x%m;
	     break;
	}
  }

  if(rem == -1) cout <<"No" << endl;
  else {
     cout << "Yes" << endl;
     vector<int> ans = mp[rem];
     for(int i=0;i<ans.size();i++){
         cout << ans[i] << " ";
     }
  }
 
return 0;
}