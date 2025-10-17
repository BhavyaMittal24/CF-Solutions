#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,k;
  cin >> n >> k;
  
  vector<int> arr(n);
  for(int i=0;i<n;i++){
     cin >> arr[i];
  }
  
//   // leftmost min index 
//   // 1 2 4 0 7 1 6 7
//      -> [front   back] <-
//   [{1,0}]
//   [{1,0} ,{2,1}]
//   [ {1,0}, {2,1}, {4,2}]
//   []
  vector<int> ans;
  deque<pair<int,int>> dq;
  for(int i=0;i<n;i++){
     // ensure that deque has the min element for the current window
     while(!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
     dq.push_back({arr[i],i});
     if( i>=k){
        if(!dq.empty() && dq.front().second == i-k) dq.pop_front();
     }
     if( i>=k-1){
        ans.push_back(dq.front().second);
        cout << dq.front().second << "  ";
     }
  }


  // -1 0 1 -3 4 -6 1 5 6
  // find first negative element in every subarray of size k
  // i  q  :       
  // 0  [-1]
  // 1  [-1,0]
  // 2  [-1,0,1]
  // 3  [0,1,-3]
  cout << endl;
  queue<pair<int,int>> q;
  for(int i=0;i<n;i++){
       // for every new window
       if(arr[i] < 0) q.push({arr[i],i});
       // once window is of size k, we need to remove the first element
       if(i >=k){
        if(q.front().second == i-k ) q.pop();
       }
       // when window is just completed
       if(i>=k-1){
          if(!q.empty()) cout << q.front().first << " ";
          else cout << " -81 "; 
       }
  }

  // code to find the leftmost index of the minimumum element in every subarray of size k
  set<pair<int,int>> st;
  for(int i=0;i<n;i++){
       st.insert({arr[i],i});
       // reaching the next subarray
       if(i>=k){
         st.erase({arr[i-k], i-k});
       }
       if(i>=k-1){
         cout << (*st.begin()).second << " ";
       }
   }
   cout << endl;

  return 0;


  
}