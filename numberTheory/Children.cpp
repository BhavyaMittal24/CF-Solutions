#include<bits/stdc++.h>
using namespace std;


long long maxFactors(vector<long long> a, int n){
   vector<long long> factorsAtPosition(n+1,0);
   map<long long, int> frogs;

   for(int i=0;i<n;i++) frogs[a[i]]++;
   long long maxFactors = 0;
    for(auto it : frogs){
       long long jump = it.first;
       long long cnt = it.second;
       for(int j = jump; j<=n; j += jump){
          factorsAtPosition[j] += cnt;
          maxFactors = max(maxFactors,factorsAtPosition[j]);
       }
    } 
   return maxFactors;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<maxFactors(a,n)<<endl;
    }
    return 0;
}