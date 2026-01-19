#include <bits/stdc++.h>
using namespace std;

void solve(){

   int n;

   cin>>n;

   vector<int> v( (n*(n-1))/2 );

   for(int &it: v) cin>>it;

   sort(v.begin(), v.end());

   vector<int> temp;

   int idx = n;

   for(int i=0;i<v.size();i += idx){

      temp.push_back(v[i]);

      idx--;

   }

   temp.push_back(1e9);

   for(int &it: temp){

    cout<<it<<" ";

   }

   cout<<endl;

}
int main(){

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
