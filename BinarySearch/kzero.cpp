// guess the kth zero
#include<bits/stdc++.h>
using namespace std;


// query returms the tptal sum feom l tp r
// number of 0s = r-l+1 - sum;

int ask(int l, int r){
   int resp;
   cout << "? " << l << " " << r << endl;
   cin >> resp;
   return resp;
}

int main(){
  
    int n;
    int t;
    int k;
    cin >> n >> t;
    cin >> k;
    
    // index (1, I) 
    // f(x) = True if number of 0s are >= k from 1,i else false
    
    int low = k;
    int high = n;
    int mid = 0;
    while( low < high){
       mid = (low+high)/2;
       int sum = ask(1,mid);
       if( mid - sum >=k) {
          high = mid;
       }  
       else low = mid+1;
    }
        
    cout << "! " << high << endl;
    return 0;
}