#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
      cin >> arr[i];
   }
   if( n <3) {
        cout << "0" << endl;
        for(auto it : arr) cout << it << " ";
        cout << endl;
        return 0;
   }
   sort(arr.begin(), arr.end());
   int i=0;
   int j =n-1;
   vector<int> ans;
   //ans.push_back(arr[j--]);
    
    while(i <= j){
        if (i == j) {
            ans.push_back(arr[i]);
        } else {
            ans.push_back(arr[j]);
            ans.push_back(arr[i]);
        }
        i++;
        j--;
    }
   int cnt = 0;
   for(int i=2;i<n;i++){
     int right = ans[i];
     int curr = ans[i-1];
     int left = ans[i-2];
     if( curr < left && curr < right) cnt++;
   }
   cout << cnt << endl;
   for(auto it : ans) cout << it << " ";
   cout << endl;
   return 0;
}

