// Maximum peaks in a window of size k and return the first starting index for that window
#include<bits/stdc++.h>
using namespace std;


void solve(){
  int n,k;
  cin >> n >> k;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  // number of mountains
  // window size is k : fixed size
  int cntPeaks = 0;
            
  // 0 1 2 3 4 5 6 
  // k = 3
  int maxPeaks = -1;
  int firstSegmentIndex = -1;
  for(int i=0;i<n;i++){
     // [a0 a1] a2 : a1 > a2 && a1 > a0
     if(i>=2 && arr[i-1] > arr[i] && arr[i-1] > arr[i-2]) cntPeaks++;
     if(i>=k){
     // as corner elements cant be peak, so if there is a peak element just after the last removed elemetn, that peak is lost
     // remove ai-k element
     // [ai-k ai-k+1 ai-k+2]
        if(arr[i-k] < arr[i-k+1] && arr[i-k+1] > arr[i-k+2]) cntPeaks--;
     }
     if(i>=k-1){
        if(cntPeaks > maxPeaks){
           maxPeaks = cntPeaks;
           firstSegmentIndex = i-k+1;
        }
     }   
  }
  cout << maxPeaks+1 << " " << firstSegmentIndex+1 << endl;

}
int main() {

  int t;
  cin >> t;
  while(t--){
     solve();
  }
  return 0;
}